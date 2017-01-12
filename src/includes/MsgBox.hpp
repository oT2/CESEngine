//by Gabriel Goude

#ifndef MSGBOX_HPP_
# define MSGBOX_HPP_

# include <list>
# include "Msg.hpp"

class MsgBox
{
    std::list<Msg *> _msgqueue;

    public:
    MsgBox();
    ~MsgBox();
    bool            queueMsg(Msg *msg);
    Msg             *getMsg();
};

#endif
