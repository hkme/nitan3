#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name( "�̵�",  ({ "duan dao", "dao", "blade" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�������Ķ̵���\n");
                set("value", 1000);
                set("material", "gold");
        }
        init_blade(10);
        setup();
}

