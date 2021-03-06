// Created by Lonely@nitan(1)

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        string htsx;
        int jnd;

        if (! arg || sscanf(arg, "%s %d", htsx, jnd) != 2) 
                return notify_fail("指令格式：allocate <后天属性> <技能点数>\n"); 

        if ((int)me->query("points") < 1)
                return notify_fail("你的人物目前没有剩下任何的技能点数可用来分配！\n"); 

        if (htsx != "膂力" && htsx != "悟性" && htsx != "根骨" && htsx != "身法"
                && htsx != "str" && htsx != "int" && htsx != "con" && htsx != "dex") 
                return notify_fail("你只可以将技能点分配到膂力、悟性、根骨和身法这四种天赋属性上！\n"); 

        if (jnd < 1) return notify_fail("技能点数的分配每次最少要求是１点。\n");

        if (jnd > (int)me->query("points"))
                return notify_fail("你没有那么多的技能点数！\n"); 

        switch (htsx)
        {
        case "膂力": 
        case "str":
                me->add("improve/str", jnd);
                tell_object(me, HIY "冥冥中，你似乎感觉有一道光芒射入你的体内！\n" NOR);
                tell_object(me, HIG "你的「" + HIR + "膂力" + NOR + HIG "」提升了！\n" NOR);
                break;
        case "悟性":
        case "int":
                me->add("improve/int", jnd);
                tell_object(me, HIY "冥冥中，你似乎感觉有一道光芒射入你的体内！\n" NOR);
                tell_object(me, HIG "你的「" + HIR + "悟性" + NOR + HIG "」提升了！\n" NOR);
                break;
        case "根骨":  
        case "con":  
                me->add("improve/con", jnd);
                tell_object(me, HIY "冥冥中，你似乎感觉有一道光芒射入你的体内！\n" NOR);
                tell_object(me, HIG "你的「" + HIR + "根骨" + NOR + HIG "」提升了！\n" NOR);
                break;
        case "身法":
        case "dex":
                me->add("improve/dex", jnd);
                tell_object(me, HIY "冥冥中，你似乎感觉有一道光芒射入你的体内！\n" NOR);
                tell_object(me, HIG "你的「" + HIR + "身法" + NOR + HIG "」提升了！\n" NOR);
                break;
        default:  
                return notify_fail("指令格式：allocate <后天属性> <技能点数>\n");
                break;
        }
        me->add("points", -jnd);

        tell_object(me, HIG "你目前还有 " + chinese_number(me->query("points")) + " 点技能点数没有分配！\n\n" NOR);
        return 1;
}

int help(object me)
{
        write(@HELP

指令格式：allocate <后天属性> <技能点数>

HELP
        );
        return 1;
}                   

