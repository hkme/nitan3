// backleg.c

#include <weapon.h>

inherit HAMMER;
inherit F_FOOD;

#include "pigpart.h"

void create()
{
        set_name("����", ({ "back leg", "tui" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һֻҰ�����ȡ�\n");
                set("unit", "��");
                set("value", 80);
                set("food_remaining", 4);
                set("food_supply", 15);
                set("wield_msg", "$Nץ��һ��$n���������е�������\n");
                set("material", "bone");
        }
        init_hammer(1);
        setup();
}

int finish_eat()
{
        if (! query("weapon_prop")) return 0;
        set_name("�еþ�������ȹ�ͷ", ({ "bone" }));
        set_weight(150);
        set("long", "һ���еþ�������ȹ�ͷ��\n");
        return 1;
}