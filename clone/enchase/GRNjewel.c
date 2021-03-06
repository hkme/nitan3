#include <ansi.h>
inherit ITEM;
// by dream
int is_enchase_ob() { return 1; }
void create()
{
        set_name(HIG "宝石" NOR, ({ "GRN jewel","jewel" }));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "一块闪烁这奇异光芒的绿色宝石。\n" NOR);
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


                        "int" : 4,           // 增加智慧

                        ////////////////////     兵器特有属性

                        "suck_jingli"   : 15, // 吸取精力
                        "suck_eff_jing" : 15, // 伤敌精力上限
                        "damage" : 40,       // 兵器伤害：+40

                   ]));

                set("enchase/aspe_data",       // 防具上附加属性汇总
                   ([
                        ////////////////////     兵防共有属性

                        "int" : 4,           // 增加智慧

                        ////////////////////     防具特有属性

                        "armor"  : 40,       // 防御能力：+40
                        "eff_jing"      : 4, // 精气上限：+4%
                        "max_jingli"    : 15, // 精力上限：+15%

                        "jing_recover_speed"   : 20, // 精气恢复速度: +20%
                        "jingli_recover_speed" : 10, // 精力恢复速度：+10%
                   ]));
        }
        setup();
}

int query_autoload()
{
        return 1;
}

