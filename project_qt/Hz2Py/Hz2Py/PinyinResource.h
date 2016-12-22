#ifndef PINYINRESOURCE_H
#define PINYINRESOURCE_H

#include <QMap>
#include <QSet>
#include <QFile>
#include <QTextStream>
class PinyinFormat {
public:
    enum Format { WITH_TONE_MARK=0, WITH_TONE_NUMBER, WITHOUT_TONE };/*带音调  带数字音调  不带音调*/
};

class PinyinResource {
private:
    PinyinResource() {}
    static QMap<QString, QString> getResource(const QString &resourceName)
    {
        QMap<QString, QString> map;
        QFile f(resourceName);
        if (!f.open(QIODevice::ReadOnly))
            return map;
        QTextStream in(&f);
        in.setCodec("utf-8");
        QString line;
        while ((line = in.readLine()) != "")
        {
            QStringList tokens = line.trimmed().split("=");
            map.insert(tokens[0], tokens[1]);
        }
        f.close();
        return map;
    }

public:
    static QMap<QString, QString> getPinyinResource() { return getResource(":/db/pinyin.db"); }
    static QMap<QString, QString> getMutilPinyinResource() { return getResource(":/db/mutil_pinyin.db"); }
    static QMap<QString, QString> getChineseResource() { return getResource(":/db/chinese.db"); }
};

/**
 * 汉字简繁体转换类
 *
 * @author stuxuhai (dczxxuhai@gmail.com)
 */
class ChineseHelper {
private:
    static QString CHINESE_REGEX;// = "[\\u4e00-\\u9fa5]";
    static QMap<QString, QString> CHINESE_MAP;// = PinyinResource.getChineseResource();
    ChineseHelper() {}

public:
    /**
     * 将单个繁体字转换为简体字
     *
     * @param c 需要转换的繁体字
     * @return 转换后的简体字
     */
    static QChar convertToSimplifiedChinese(QChar c) {
        QString simplifiedChinese = CHINESE_MAP.value(c);//繁体字---->简体字 对照表对个
        return simplifiedChinese.isEmpty() ? c : simplifiedChinese.at(0);
    }

    /**
     * 将单个简体字转换为繁体字
     *
     * @param c 需要转换的简体字
     * @return 转换后的繁字体
     */
    static QChar convertToTraditionalChinese(QChar c) {
        QString simpTraditionaChinese = CHINESE_MAP.key(c);// 简体字---->繁体字 对照表 可能对应多个繁体字
        return simpTraditionaChinese.isEmpty() ? c : simpTraditionaChinese.at(0);
    }

    /**
     * 将繁体字转换为简体字
     *
     * @param str 需要转换的繁体字
     * @return 转换后的简体体
     */
    static QString convertToSimplifiedChinese(const QString& str) {
        QString sb;
        for (int i = 0, len = str.length(); i < len; i++)
            sb += convertToSimplifiedChinese(str[i]);
        return sb;
    }

    /**
     * 将简体字转换为繁体字
     *
     * @param str 需要转换的简体字
     * @return 转换后的繁字体
     */
    static QString convertToTraditionalChinese(const QString& str) {
        QString sb;
        for (int i = 0, len = str.length(); i < len; i++)
            sb += convertToTraditionalChinese(str[i]);
        return sb;
    }

    /**
     * 判断某个字符是否为繁体字
     *
     * @param c 需要判断的字符
     * @return 是繁体字返回true，否则返回false
     */
    static bool isTraditionalChinese(const QChar c) { return CHINESE_MAP.keys().indexOf(c)!=-1; }

    /**
     * 判断某个字符是否为汉字
     *
     * @param c 需要判断的字符
     * @return 是汉字返回true，否则返回false
     * 汉子unicode范围【0x4e00，0x9fa5】
     */
    static bool isChinese(const QChar c) { return '〇' == c || (c.unicode() >= 0x4e00 && c.unicode() <= 0x9fa5); }//.indexOf(QRegExp(CHINESE_REGEX))!=-1); }

    /**
     * 判断字符串中是否包含中文
     * @param str 字符串
     * @return 包含汉字返回true，否则返回false
     */
    static bool containsChinese(const QString& str) {
        for (int i = 0, len = str.length(); i < len; i++)
            if (isChinese(str[i]))
                return true;
        return false;
    }
};
QString ChineseHelper::CHINESE_REGEX = "[\\u4e00-\\u9fa5]";
QMap<QString, QString> ChineseHelper::CHINESE_MAP = PinyinResource::getChineseResource();


/**
 * 汉字转拼音类
 *
 * @author stuxuhai (dczxxuhai@gmail.com)
 */
class PinyinHelper {
private:
    static QMap<QString, QString> PINYIN_TABLE;// = PinyinResource.getPinyinResource();
    static QMap<QString, QString> MUTIL_PINYIN_TABLE;// = PinyinResource.getMutilPinyinResource();
    static QString PINYIN_SEPARATOR;// = ","; // 拼音分隔符
    static QChar CHINESE_LING;// = '〇';
    static QString ALL_UNMARKED_VOWEL;// = "aeiouv";
    static QString ALL_MARKED_VOWEL;// = "āáǎàēéěèīíǐìōóǒòūúǔùǖǘǚǜ"; // 所有带声调的拼音字母

    PinyinHelper() {}

    /**
     * 将带声调格式的拼音转换为数字代表声调格式的拼音
     *
     * @param pinyinArrayString 带声调格式的拼音
     * @return 数字代表声调格式的拼音
     */
private:
    static QStringList convertWithToneNumber(const QString& pinyinArrayString) {
        QStringList pinyinArray = pinyinArrayString.split(PINYIN_SEPARATOR);
        for (int i = pinyinArray.length() - 1; i >= 0; i--) {
            bool hasMarkedChar = false;
            QString originalPinyin = pinyinArray[i].replace("ü", "v"); // 将拼音中的ü替换为v

            for (int j = originalPinyin.length() - 1; j >= 0; j--) {
                QChar originalChar = originalPinyin[j];

                // 搜索带声调的拼音字母，如果存在则替换为对应不带声调的英文字母
                if (originalChar < 'a' || originalChar > 'z') {
                    int indexInAllMarked = ALL_MARKED_VOWEL.indexOf(originalChar);
                    int toneNumber = indexInAllMarked % 4 + 1; // 声调数
                    QChar replaceChar = ALL_UNMARKED_VOWEL.at(((indexInAllMarked - indexInAllMarked % 4)) / 4);
                    pinyinArray[i] = originalPinyin.replace(QString(originalChar), QString(replaceChar)) + QString::number(toneNumber);
                    hasMarkedChar = true;
                    break;
                }
            }
            if (!hasMarkedChar) {
                // 找不到带声调的拼音字母说明是轻声，用数字5表示
                pinyinArray[i] = originalPinyin + "5";
            }
        }

        return pinyinArray;
    }

    /**
     * 将带声调格式的拼音转换为不带声调格式的拼音
     *
     * @param pinyinArrayString 带声调格式的拼音
     * @return 不带声调的拼音
     */
    static QStringList convertWithoutTone(QString pinyinArrayString) {
        QStringList pinyinArray;
        for (int i = ALL_MARKED_VOWEL.length() - 1; i >= 0; i--) {
            QChar originalChar = ALL_MARKED_VOWEL.at(i);
            QChar replaceChar = ALL_UNMARKED_VOWEL.at(((i - i % 4)) / 4);
            pinyinArrayString = pinyinArrayString.replace(QString(originalChar), QString(replaceChar));
        }
        // 将拼音中的ü替换为v
        pinyinArray = pinyinArrayString.replace("ü", "v").split(PINYIN_SEPARATOR);

        // 去掉声调后的拼音可能存在重复，做去重处理
        QSet<QString> pinyinSet;
        foreach (QString pinyin, pinyinArray) {
            pinyinSet.insert(pinyin);
        }

        return pinyinSet.toList();
    }

    /**
     * 将带声调的拼音格式化为相应格式的拼音
     *
     * @param pinyinString 带声调的拼音
     * @param pinyinFormat 拼音格式：WITH_TONE_NUMBER--数字代表声调，WITHOUT_TONE--不带声调，WITH_TONE_MARK--带声调
     * @return 格式转换后的拼音
     */
    static QStringList formatPinyin(QString pinyinString, PinyinFormat::Format pinyinFormat) {
        if (pinyinFormat == PinyinFormat::WITH_TONE_MARK) {
            return pinyinString.split(PINYIN_SEPARATOR);
        } else if (pinyinFormat == PinyinFormat::WITH_TONE_NUMBER) {
            return convertWithToneNumber(pinyinString);
        } else if (pinyinFormat == PinyinFormat::WITHOUT_TONE) {
            return convertWithoutTone(pinyinString);
        }
        return QStringList();
    }

    /**
     * 将单个汉字转换为相应格式的拼音
     *
     * @param c 需要转换成拼音的汉字
     * @param pinyinFormat 拼音格式：WITH_TONE_NUMBER--数字代表声调，WITHOUT_TONE--不带声调，WITH_TONE_MARK--带声调
     * @return 汉字的拼音
     */
    static QStringList convertToPinyinArray(QChar c, PinyinFormat::Format pinyinFormat)
    {
        QString pinyin = PINYIN_TABLE.value(QString(c));


        if (!pinyin.isEmpty())
            return formatPinyin(pinyin, pinyinFormat);


        return QStringList();
    }

public:
    /**
     * 将单个汉字转换成带声调格式的拼音
     *
     * @param c 需要转换成拼音的汉字
     * @return 字符串的拼音
     */
    static QStringList convertToPinyinArray(QChar c) { return convertToPinyinArray(c, PinyinFormat::WITH_TONE_MARK); }

    /**
     * 将字符串转换成相应格式的拼音
     *
     * @param str 需要转换的字符串
     * @param separator 拼音分隔符
     * @param pinyinFormat 拼音格式：WITH_TONE_NUMBER--数字代表声调，WITHOUT_TONE--不带声调，WITH_TONE_MARK--带声调
     * @return 字符串的拼音
     */
    static QString convertToPinyinString(const QString& s, const QString& separator, PinyinFormat::Format pinyinFormat) {
        QString str = ChineseHelper::convertToSimplifiedChinese(s);
        QString sb;
        for (int i = 0, len = str.length(); i < len; i++)
        {
            QChar c = str[i];
            // 判断是否为汉字或者〇
            if (ChineseHelper::isChinese(c)/* || c == CHINESE_LING*/)
            {
                // 多音字识别处理
                bool isFoundFlag = false;
                int rightMove = 3;

                // 将当前汉字依次与后面的3个、2个、1个汉字组合，判断下是否存在多音字词组
                for (int rightIndex = (i + rightMove) < len ? (i + rightMove) : (len - 1)   ;  rightIndex > i   ; rightIndex--)
                {
                    QString cizu = str.mid(i, rightIndex + 1);
                    if (MUTIL_PINYIN_TABLE.keys().indexOf(cizu)!=-1)
                    {
                        QStringList pinyinArray = formatPinyin(MUTIL_PINYIN_TABLE.value(cizu), pinyinFormat);
                        for (int j = 0, l = pinyinArray.length(); j < l; j++)
                        {
                            sb.append(pinyinArray[j]);
                            if (j < l - 1)
                            {
                                sb.append(separator);
                            }
                        }
                        i = rightIndex;
                        isFoundFlag = true;
                        break;
                    }
                }
                if (!isFoundFlag)
                {
                    QStringList pinyinArray = convertToPinyinArray(str[i], pinyinFormat);
                    if (!pinyinArray.isEmpty())
                    {
                        sb.append(pinyinArray[0]);
                    } else
                    {
                        sb.append(str[i]);
                    }
                }
                if (i < len - 1)
                {
                    sb.append(separator);
                }
            }
            else
            {
                sb.append(c);
                if ((i + 1) < len && ChineseHelper::isChinese(str[i + 1]))//添加 分隔符
                {
                    sb.append(separator);
                }
            }

        }
        return sb;
    }

    /**
     * 将字符串转换成带声调格式的拼音
     *
     * @param str 需要转换的字符串
     * @param separator 拼音分隔符
     * @return 转换后带声调的拼音
     */
    static QString convertToPinyinString(const QString& str, const QString& separator) {
        return convertToPinyinString(str, separator, PinyinFormat::WITH_TONE_MARK);
    }

    /**
     * 判断一个汉字是否为多音字
     *
     * @param c 汉字
     * @return 判断结果，是汉字返回true，否则返回false
     */
    static bool hasMultiPinyin(char c) {
        QStringList pinyinArray = convertToPinyinArray(c);
        if (!pinyinArray.isEmpty() && pinyinArray.length() > 1) {
            return true;
        }
        return false;
    }

    /**
     * 获取字符串对应拼音的首字母
     *
     * @param str 需要转换的字符串
     * @return 对应拼音的首字母
     */
    static QString getShortPinyin(const QString& str) {
        QString separator = "#"; // 使用#作为拼音分隔符
        QString sb;

        QChar* charArray = new QChar[str.length()];
        for (int i = 0, len = str.length(); i < len; i++) {
            QChar c = str[i];

            // 首先判断是否为汉字或者〇，不是的话直接将该字符返回
            if (!ChineseHelper::isChinese(c) && c != CHINESE_LING) {
                charArray[i] = c;
            } else {
                int j = i + 1;
                sb.append(c);

                // 搜索连续的汉字字符串
                while (j < len && (ChineseHelper::isChinese(str[j]) || str[j] == CHINESE_LING)) {
                    sb.append(str[j]);
                    j++;
                }
                QString hanziPinyin = convertToPinyinString(sb, separator, PinyinFormat::WITHOUT_TONE);
                QStringList pinyinArray = hanziPinyin.split(separator);
                foreach (QString string, pinyinArray) {
                    charArray[i] = string[0];
                    i++;
                }
                i--;
                sb.clear();
            }
        }
        QString ss(charArray);
        delete [] charArray;
        return ss;
    }

};
QMap<QString, QString> PinyinHelper::PINYIN_TABLE = PinyinResource::getPinyinResource();
QMap<QString, QString> PinyinHelper::MUTIL_PINYIN_TABLE = PinyinResource::getMutilPinyinResource();
QString PinyinHelper::PINYIN_SEPARATOR = ","; // 拼音分隔符
QChar PinyinHelper::CHINESE_LING = '〇';
QString PinyinHelper::ALL_UNMARKED_VOWEL = "aeiouv";
QString PinyinHelper::ALL_MARKED_VOWEL = "āáǎàēéěèīíǐìōóǒòūúǔùǖǘǚǜ"; // 所有带声调的拼音字母
#endif // PINYINRESOURCE_H
