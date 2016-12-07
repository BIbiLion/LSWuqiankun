#ifndef MODULE_H
#define MODULE_H
#include <QProcess>
#include <QDebug>
class Module
{
public:
   static Module& getInstance()
   {
      static Module _module;
      return _module;
   }


//   void ReleaseInstance()
//   {
//      delete m_process;
//      m_process=NULL;
//   }

   int instllModule();
   int removeModule();

private:

private:
    QProcess *m_process;


    Module();
    Module(const Module&);
    Module& operator=(const Module&);


};

#endif // MODULE_H
