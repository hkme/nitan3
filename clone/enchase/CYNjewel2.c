#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(CYN "宝石" NOR, ({ "CYN jewel2","jewel2" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", CYN "一颗青光闪闪的精美宝石，华丽异常。\n" NOR);
                set("unit", "块");
                set("value", 100000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。\n" NOR);
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。\n" NOR);
                    
                set("enchase/type", "all");   // 可镶嵌的道具类型"all"或"sword"或"blade"或"cloth"等
                set("enchase/cur_firm", 90);  // 抗磨损度
                set("enchase/wspe_data",      // 兵器上附加属性汇总
                   ([
                        ////////////////////     兵防共有属性


                        "kar" : 2,           // 增加福源

                        ////////////////////     兵器特有属性

                       "attack" : 20,       // 攻击等级：+20
                        "xuruo_status"  : 1,  // 战力削弱(虚弱)1秒
                        "suck_jingli"   : 5, // 吸取精力5

                   ]));

                set("enchase/aspe_data",       // 防具上附加属性汇总
                   ([
                        ////////////////////     兵防共有属性

                        "kar" : 2,           // 增加福源

                        ////////////////////     防具特有属性

                        "avoid_poison"  : 20, // 毒性回避：20%
                        "dodge"  : 20,       // 轻功等级：+20
                        "reduce_busy"   : 10, // 化解忙乱：10%

                        "neili_recover_speed"  : 4, // 内力恢复速度：+4%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

