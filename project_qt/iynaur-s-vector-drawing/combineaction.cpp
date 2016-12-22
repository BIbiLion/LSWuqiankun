#include "combineaction.h"

CombineAction::CombineAction()
{
    //actiontype=Combine;
}
ActionType CombineAction::actiontype(){
    return Combine;
}
QString CombineAction::name(){
    return "Combine";
}
CombineAction::~CombineAction(){
    //delete com;
}
void CombineAction::undo(){
    for(int i=shapes.size()-1;i>=0;i--){
        allShapes->insert(indexOfShapes.at(i),shapes.at(i));
    }
    //qDebug()<<shapes.indexOf(tmp->com)<<shapes.size();
    allShapes->removeOne(com);
    pickedShapes =  shapes;
}
void CombineAction::redo(){
    foreach(shared_ptr<GeneralShape> sp,shapes){
        allShapes->removeOne(sp);
    }

    allShapes->append(com);
    QList<shared_ptr<GeneralShape>> list;
    list.append(com);
    pickedShapes =list;
}
