#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(BLU "稀世宝石" NOR, ({ "BLU jewel3","jewel3" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", BLU "一颗蓝光闪闪的精美宝石，给人以不同寻常的感觉。\n" NOR);
                set("unit", "块");
                set("value", 120000);
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


                            "kar" : 3,           // 增加福源

                        ////////////////////     兵器特有属性

                            "light_attack"  : 30, // 闪电攻击
                            "add_damage"    : 8, // 追加伤害8%
                            "suck_eff_qi"   : 10, // 伤敌气血上限

                   ]));

                set("enchase/aspe_data",       // 防具上附加属性汇总
                   ([
                        ////////////////////     兵防共有属性

                           "kar" : 3,           // 增加福源

                        ////////////////////     防具特有属性

                            "reduce_light"  : 30, // 化解闪电：30%
                            "avoid_poison"  : 30, // 毒性回避：30%
                            "reduce_damage" : 15, // 化解伤害：15%

                            "qi_recover_speed"     : 15, // 气血恢复速度：+15%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

