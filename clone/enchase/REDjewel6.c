#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(RED "魔之宝石" NOR, ({ "RED jewel6","jewel6" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", RED "一块闪烁这奇异光芒的红色宝石，"
                    "让人感到一阵阵的心悸。\n" NOR);
                set("unit", "块");
                set("value", 180000);
                set("no_identify", 1);
                set("wear_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "戴在头上。\n" NOR);
                set("remove_msg", HIC "$N" HIC "轻轻地把$n"
                    HIC "从头上摘了下来。\n" NOR);
                
                set("enchase/SN", 6);    
                set("enchase/type", "all");   // 可镶嵌的道具类型"all"或"sword"或"blade"或"cloth"等
                set("enchase/cur_firm", 90);  // 抗磨损度
                set("enchase/wspe_data",      // 兵器上附加属性汇总
                   ([
                        ////////////////////     兵防共有属性


                        "str" : 8,           // 增加膂力
                        "dex" : 8,           // 增加根骨

                        ////////////////////     兵器特有属性

                        "attack" : 80,        // 攻击等级：+80
                        "damage" : 80,        // 兵器伤害：+80
                        "fire_attack"   : 80, // 火焰攻击
                        "perferm_ap"    : 10,   // 绝招命中：+10%
                        "add_damage"    : 7, // 追加伤害5%

                   ]));

                set("enchase/aspe_data",       // 防具上附加属性汇总
                   ([
                        ////////////////////     兵防共有属性

                        "str" : 8,            // 增加膂力
                        "dex" : 8,            // 增加根骨
                        ////////////////////     防具特有属性

                        "reduce_fire"   : 70, // 化解火焰：70%
                        "reduce_damage" : 70, // 化解伤害：70%
                        "max_neili"     : 15, // 内力上限：+15%
                        "perform_dp"    : 8,  // 绝招防御：+8%

                        "qi_recover_speed"     : 30, // 气血恢复速度：+30%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}


