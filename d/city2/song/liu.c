
#include <ansi.h>
inherit NPC;

string *degree_desc = ({
       HIR "总督" NOR,
       MAG "兵部侍郎" NOR,
       MAG "兵部尚书" NOR,
       HIB "镇北节度使" NOR,
       HIB "征讨大将军" NOR,
       HIW "兵马大元帅" NOR,
});
string clear_degree(string arg);
string ask_chubing(object me);
int ask_degree();
int add_degree(object ob, int lv);

void create()
{
        set_name("刘公公", ({"liu gonggong", "liu"}));
        set("gender", "无性");
        set("age", random(20) + 20);

        set("long", "这是一个京城皇宫中的一名太监，负责为皇帝传送奏本。\n");
        set("combat_exp", 800000);
        set("attitude", "peaceful");
        set("max_qi", 3000);
        set("max_jing", 2000);
        set("max_neili", 2000);
        set("neili", 1000);
        set("no_get", 1);
        set("inquiry", ([
                 "策封" :   (: ask_degree :),
                 "出兵" :   (: ask_chubing :),
        ]));

        setup();
        carry_object("clone/cloth/cloth")->wear();
}

int ask_degree()
{
        int lv;
        object ob = this_player();

        if (ob->query_temp("degree_jungong") )
        {
                command("say 大人稍安勿躁，"
                        + "咱家已经启奏圣上了，还是先耐心恭候圣上旨意吧！\n");
                return 1;
        }

        if (ob->query("guo_shoucheng/reward") >
                (100 * (1 + ob->query("degree_jungong")) * (1 + ob->query("degree_jungong"))))
        lv = ob->query("degree_jungong") + 1;

        if (lv > (sizeof(degree_desc) + 8))
        {
                command("say 大人已经官居极品，位高权重，该多考虑些"
                        + "为国家社稷出力才是！\n");
                return 1;
        }

        if (lv <= ob->query("degree_jungong") || ob->query("degree_jungong") < 8)
        {
                command("say 要获得更高的策封，大人所立军功好象不够啊！\n");
                return 1;
        }

        command("say 大人请稍候，咱家这就立刻禀报圣上，为大人请封！\n");

        //  remove_call_out("add_degree");
        call_out("add_degree", 10, ob, lv);
        ob->set_temp("degree_jungong",1);
        return 1;
}

int add_degree(object ob, int lv)
{
        string degree, old_degree;
        degree = degree_desc[lv - 9];

        if (! ob) return;

        if (ob->query("degree")) old_degree = ob->query("degree");
        else old_degree = "";

        message("channel:rumor", MAG"【大宋京城】"NOR + YEL
                + CHINESE_D->chinese_date((time() - 14 * 365 * 24 * 60 * 60))
                + "......\n"NOR,
                users());

        message("channel:rumor", MAG"【大宋京城】"HIY"奉天承命，皇帝诏曰："
                + "策封 " + old_degree + " " + HIW + ob->query("name")
                + HIY" 为大宋 "NOR + degree + HIY"，钦此！\n"NOR,
                users());
        ob->delete_temp("degree_jungong");

        if (ob->query("degree"))
        {
                if (ob->query("degree_ask"))
                        degree = HIM " ☆ " NOR + clear_degree(ob->query("degree"))
                               + HIM " ☆ " NOR + degree + HIM " ☆ "NOR;
                else
                        degree = HIM " ☆ " NOR + clear_degree(ob->query("degree"))
                               + degree + HIM " ☆ " NOR;
        } else
                degree = HIM " ☆ " NOR + degree
                       + HIM " ☆ " NOR;

        ob->set("degree_jungong", lv);
        ob->set("degree", degree);
        ob->add("weiwang", lv * 200);
        return 1;
}

string clear_degree(string arg)
{
        if ((strsrch(arg, HIR "提督" NOR) >= 0)
        ||  (strsrch(arg, HIR "总督" NOR) >= 0)
        ||  (strsrch(arg, MAG "兵部侍郎" NOR) >= 0)
        ||  (strsrch(arg, MAG "兵部尚书" NOR) >= 0)
        ||  (strsrch(arg, HIB "镇北节度使" NOR) >= 0)
        ||  (strsrch(arg, HIB "征讨大将军" NOR) >= 0)
        ||  (strsrch(arg, HIW "兵马大元帅" NOR) >= 0)
        ||  (strsrch(arg, HIM " ☆ " NOR) >= 0))
        {
                arg = replace_string(arg, HIR "总督" NOR, "");
                arg = replace_string(arg, MAG "兵部侍郎" NOR, "");
                arg = replace_string(arg, MAG "兵部尚书" NOR, "");
                arg = replace_string(arg, HIB "镇北节度使" NOR, "");
                arg = replace_string(arg, HIB "征讨大将军" NOR, "");
                arg = replace_string(arg, HIW "兵马大元帅" NOR, "");
                arg = replace_string(arg, HIR "提督" NOR, "");
                arg = replace_string(arg, HIM " ☆ " NOR, "");
        }
        return arg;
}

string ask_chubing(string arg)
{
        object me;

        me = this_player();
        return WAR_D->ask_kingwar(me);
}
