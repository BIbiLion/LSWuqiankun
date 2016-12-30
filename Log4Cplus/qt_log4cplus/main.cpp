
#include <exception>
#include <iostream>
#include <string>
#include <sstream>
#include "log4cplus/logger.h"
#include "log4cplus/consoleappender.h"
#include "log4cplus/helpers/appenderattachableimpl.h"
#include "log4cplus/helpers/loglog.h"
#include "log4cplus/helpers/pointer.h"
#include "log4cplus/helpers/property.h"
#include "log4cplus/spi/loggingevent.h"
#include "loglevel.h"


#include "log4cplus/loggingmacros.h"// HONG define   LOG4CPLUS_DEBUG(LOGGER ,Message) etc
using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;
using namespace log4cplus::spi;

static void
printAppenderList(const SharedAppenderPtrList& list)
{
   cout << "List size: " << list.size() << endl;
   for(SharedAppenderPtrList::const_iterator it=list.begin(); it!=list.end(); ++it) {
       log4cplus::tcout << "Loop Body: Appender name = " << (*it)->getName()
                        << endl;
   }
}


// This appender does not call destructorImpl(), which is wrong.
class BadDerivedAppender
    : public Appender
{
public:
    virtual void close ()
    { }

    virtual void append (const log4cplus::spi::InternalLoggingEvent&)
    { }
};

#include <QCoreApplication>
#include <QDebug>
#include "fileappender.h"
#include "log4cplus/helpers/loglog.h"
/*
 *LogLog类实现了debug, warn, error 函数用于logcplus运行时显示log4cplus自身的调试、警告或错误信息，是对标准输出的简单封装，
 *它也可以用来进行简单的日志输出。
 *LogLog 同时提供了两个方法来进一步控制所输出的信息，
 *其中setInternalDebugging()方法用来控制是否屏蔽输出信息中的调试信息，当输入参数为false则屏蔽，缺省设置为false。
 *setQuietMode()方法用来控制是否屏蔽所有输出信息，当输入参数为true则屏蔽，缺省设置为false。
 *i have a question about the result which is differrnt the demo's output?
 *
 *loglog output debug warn or error infomations;
 **/
/*
 *Layout   3type:
 *1.default simpleLayout
 *2.patternLayout moshiLayout
 *3.TTCCLayout
 **/

void printMsg()
{
    std::cout<<"enter PrintMsg.....\n";
    LogLog::getLogLog()->debug("this is a debug stateMent");
    LogLog::getLogLog()->warn("this is a warn stateMent");
    LogLog::getLogLog()->error("this is a error");
    std::cout<<"leave PrintMsg\n";
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //qDebug()<<"hellojjjjjj ";

    /*
   //test used
{
   // this is a demo about how to use the log4cplus
    //1.output device
  //  SharedObjectPtr<Appender> _append(new ConsoleAppender);//output ConsoleAppender device
        SharedObjectPtr<Appender> _append(new FileAppender("testFile.log"));//output FileAppender device
     _append->setName("append for test");

     //2.layout formate
     std::string pattern="%d -%m";
     std::auto_ptr<Layout> _layout(new PatternLayout(pattern));

     //3. Appender attach layout
     _append->setLayout(_layout);

     //4.logger attach appender
      Logger _logger= log4cplus::Logger::getInstance("logger_name");
      _logger.addAppender(_append);

     //set Priority for the logger
      _logger.setLogLevel(ALL_LOG_LEVEL);

      //active
   LOG4CPLUS_DEBUG(_logger, "This is the  FIRST log message...\n");// output **Appender
   log4cplus::tcout << "Exiting main()..." << endl; // output Console
    }

    */

    //loglog
    printMsg();//default don't dispaly the loglog infomations

    std::cout<<"\n\nturn on the debug----dispaly the debug information \n ";
    LogLog::getLogLog()->setInternalDebugging(true);
    printMsg();

    std::cout<<" ---quit mode--"<<std::endl;
    LogLog::getLogLog()->setQuietMode(true);
    printMsg();

/*
  //demo test
  log4cplus::initialize ();
    LogLog::getLogLog()->setInternalDebugging(true);
    {
        try {
            SharedObjectPtr<Appender> append_1(
                new ConsoleAppender(false, true));
            append_1->setName(LOG4CPLUS_TEXT("First"));

            SharedObjectPtr<Appender> append_2(new ConsoleAppender());
            append_2->setName(LOG4CPLUS_TEXT("Second"));

            // Test that we get back the same layout as we set.

            Layout * layout_2;
            append_2->setLayout(
                std::auto_ptr<Layout>(layout_2 = new log4cplus::SimpleLayout));
            if (append_2->getLayout () != layout_2)
                return 1;

            // Default error handler should be set.

            if (! append_2->getErrorHandler ())
                return 2;

            // Test warning on NULL handler.

            append_2->setErrorHandler (std::auto_ptr<ErrorHandler>());

            // Set working error handler.

            std::auto_ptr<ErrorHandler> errorHandler (new OnlyOnceErrorHandler);
            append_2->setErrorHandler (errorHandler);

            // Test logging through instantiated appenders.

            InternalLoggingEvent event(
                Logger::getInstance(LOG4CPLUS_TEXT("test")).getName(),
                DEBUG_LOG_LEVEL, LOG4CPLUS_TEXT("This is a test..."), __FILE__,
                __LINE__, "main");

            AppenderAttachableImpl aai;
            aai.addAppender(append_1);
            aai.addAppender(append_2);
            aai.addAppender(append_1);
            aai.addAppender(append_2);
            aai.addAppender(SharedAppenderPtr());
            printAppenderList(aai.getAllAppenders());

            aai.removeAppender(append_2);
            printAppenderList(aai.getAllAppenders());

            aai.removeAppender(LOG4CPLUS_TEXT("First"));
            aai.removeAppender(SharedAppenderPtr());
            printAppenderList(aai.getAllAppenders());

            aai.addAppender(append_1);
            aai.addAppender(append_2);
            aai.addAppender(append_1);
            aai.addAppender(append_2);
            log4cplus::tcout << "Should be First: "
                             << aai.getAppender(LOG4CPLUS_TEXT("First"))->getName() << endl;
            log4cplus::tcout << "Should be Second: "
                             << aai.getAppender(LOG4CPLUS_TEXT("Second"))->getName() << endl
                             << endl;
            append_1->doAppend(event);
            append_2->doAppend(event);

            // Test appending to closed appender error handling.

            append_2->close ();
            append_2->doAppend (event);

            // Test appender's error handling for wrong layout.

            {
                tistringstream propsStream (
                    LOG4CPLUS_TEXT ("layout=log4cplus::WrongLayout"));
                Properties props (propsStream);
                SharedObjectPtr<Appender> append (
                    new ConsoleAppender (props));
                append->setName (LOG4CPLUS_TEXT ("Third"));
            }

            // Test threshold parsing.

            {
                tistringstream propsStream (
                    LOG4CPLUS_TEXT ("Threshold=ERROR"));
                Properties props (propsStream);
                SharedObjectPtr<Appender> append (
                    new ConsoleAppender (props));
                append->setName (LOG4CPLUS_TEXT ("Fourth"));
            }

            // Test threshold parsing of wrong log level.

            {
                tistringstream propsStream (
                    LOG4CPLUS_TEXT ("Threshold=WRONG"));
                Properties props (propsStream);
                SharedObjectPtr<Appender> append (
                    new ConsoleAppender (props));
                append->setName (LOG4CPLUS_TEXT ("Fifth"));
            }

            // Test wrong filter parsing.

            {
                tistringstream propsStream (
                    LOG4CPLUS_TEXT ("filters.1=log4cplus::spi::WrongFilter"));
                Properties props (propsStream);
                SharedObjectPtr<Appender> append (
                    new ConsoleAppender (props));
                append->setName (LOG4CPLUS_TEXT ("Sixth"));
            }

            // Test error reporting of badly coded appender.

            {
                BadDerivedAppender appender;
                appender.setName (LOG4CPLUS_TEXT ("Seventh"));
            }
        }
        catch(std::exception const & e) {
            log4cplus::tcout << "**** Exception occured: " << e.what() << endl;
        }
    }

    log4cplus::tcout << "Exiting main()..." << endl;

*/
    return a.exec();
}
