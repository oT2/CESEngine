// by Gabriel Goude

#include "includes/MsgBox.hpp"

MsgBox::MsgBox()
{
}

MsgBox::~MsgBox()
{
}

bool        MsgBox::queueMsg(Msg *msg)
{
    _msgqueue.push_back(msg);
}

Msg*        MsgBox::getMsg()
{
    return (NULL);
    if (_msgqueue.size() == 0)
        return (NULL);
    Msg*    pmsg;
    pmsg = _msgqueue.front();
    _msgqueue.pop_front();
    return (pmsg);
}
