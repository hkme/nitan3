#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("楞伽经", ({ "shu", "book" }));
        set_weight(50);
        set("no_drop", "这样东西不能离开你。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "本");
                set("long",
                        "这是一册佛经。经文夹缝中写着一些字迹模糊的字句，似乎提到一些呼吸方法什麽的。\n");
                set("value", 500);
                set("material", "silk");
        }
}

void init()
{
        if( this_player() == environment() )
        {
                add_action("do_qu", "qu");
                add_action("do_qu", "na");
        }
}

int do_qu(string arg)
{
        object me, book;
        
        me = this_player();

        if (! arg || ! id(arg))
                return 0;

        if (! me->query("jiuyang/zhang"))
        {
                write("什么？\n");
                return 1;
        }

        message_vision(WHT "\n$N" WHT "拆开经文夹缝，发现里面留有个秘籍"
                       "，写着「" HIR "九阳真经"
                       NOR + WHT "」。\n" NOR, me);

        tell_object(me, HIC "你获得了一本九阳真经。\n" NOR);
        
        book = new("/clone/book/jiuyang-book");
        book->move(me, 1);
        destruct(this_object());
        return 1;
}
