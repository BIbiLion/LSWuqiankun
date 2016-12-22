#ifndef MD5_H
#define MD5_H
#include <QString>
#include <QFile>
/* Type define */
typedef unsigned char byte;
typedef unsigned long ulong;
/* MD5 declaration. */
class MD5 {
public:
	MD5();
	MD5(const void *input, size_t length);
	MD5(const QString &str);
	void update(const void *input, size_t length);
	void update(const QString &str);
	void update(QFile& qfile);
	const byte* digest();
	QString toString();
	void reset();
private:
	void update(const byte *input, size_t length);
	void final();
	void transform(const byte block[64]);
	void encode(const ulong *input, byte *output, size_t length);
	void decode(const byte *input, ulong *output, size_t length);
	QString bytesToHexString(const byte *input, size_t length);

	/* class uncopyable */
	MD5(const MD5&);
	MD5& operator=(const MD5&);
private:
	ulong _state[4];	/* state (ABCD) */
	ulong _count[2];	/* number of bits, modulo 2^64 (low-order word first) */
	byte _buffer[64];	/* input buffer */
	byte _digest[16];	/* message digest */
	bool _finished;		/* calculate finished ? */

	static const byte PADDING[64];	/* padding for calculate */
	static const char HEX[16];
	static const size_t BUFFER_SIZE = 1024;
};

#endif/*MD5_H*/
