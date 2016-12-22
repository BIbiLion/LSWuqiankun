#include "addaction.h"
AddAction::AddAction(){
    //actiontype=Add;

}

AddAction::AddAction(shared_ptr<GeneralShape>sp)
{
    //actiontype=Add;
    shapes.append(sp);

}

ActionType AddAction::actiontype(){
    return Add;
}
QString AddAction::name(){
    return "Add";
}
void AddAction::undo(){
    foreach (shared_ptr<GeneralShape>sp,shapes){
//    del(sp);
    allShapes->removeOne(sp);
    }
    pickedShapes.clear();
}
void AddAction::redo(){
    foreach (shared_ptr<GeneralShape>sp,shapes){
        allShapes->append(sp);
    }
    pickedShapes =  shapes;
}
