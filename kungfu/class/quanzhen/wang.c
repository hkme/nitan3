// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include "quanzhen.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

mixed  ask_skill1();
mixed  ask_skill2();
mixed  ask_skill3();
mixed  ask_skill4();
mixed  ask_skill5();
mixed  ask_skill6();
string ask_jiuyin();
string ask_duan();

void create()
{
        set_name("王重阳", ({ "wang chongyang", "wang", "chongyang" }));
        set("long", @LONG
他就是全真教的开山祖师、首代掌教王重阳王
真人。他白须飘飘，宽袍缓袖，眉目清癯，颇
有些仙风道骨的味道。他本来一腔热血欲报效
国家力抗金兵，可惜朝廷腐败，于是便心灰意
冷，兼此时又从道德经中悟得了天地万物滋生
的大道，从而手创全真教。
LONG);
        set("title", "全真派开山祖师");
        set("nickname", HIW "中神通" NOR);
        set("age", 76);
        set("gender", "男性");
        set("class", "taoist");
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 33);
        set("int", 35);
        set("con", 38);
        set("dex", 33);
        set("max_qi", 8000);
        set("max_jing", 8000);
        set("neili", 10000);
        set("jingli", 8000);
        set("max_neili", 10000);
        set("max_jingli", 8000);
        set("jiali", 250);
        set("level", 70);
        set("combat_exp", 5000000);
        set("no_get", 1);

        set_skill("force", 400);
        set_skill("quanzhen-jianzhen", 500);
        set_skill("array", 500);         
        set_skill("quanzhen-xinfa", 480);
        // set_skill("xuanmen-neigong", 380);
        set_skill("unarmed", 480);
        set_skill("xiantian-gong", 400);
        set_skill("dodge", 480);
        // set_skill("tianshan-feidu", 360);
        set_skill("jinyan-gong", 480);
        set_skill("parry", 480);
        // set_skill("jinguan-yusuo", 380);
        set_skill("strike", 480);
        set_skill("chongyang-shenzhang", 460);
        set_skill("haotian-zhang", 480);
        set_skill("finger", 480);
        set_skill("zhongnan-zhi", 460);
        set_skill("yiyang-zhi", 480);
        // set_skill("qixing-shou", 380);
        set_skill("sword", 480);
        // set_skill("qixing-jian", 360);
        // set_skill("tonggui-jian", 360);
        set_skill("quanzhen-jian", 480);
        // set_skill("tiangang-chenfa", 340);
        set_skill("taoism", 400);
        set_skill("literate", 440);
        set_skill("martial-cognize", 400);
        set_skill("medical", 470);
        set_skill("liandan-shu", 470);
	set_skill("cuff",470);
	set_skill("whip",470);
	set_skill("chunyang-quan",470);
	set_skill("duanyun-bian",470);
        set_skill("array",400);
	set_skill("beidou-zhenfa", 400);
	        
        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jian");
        // map_skill("whip", "tiangang-chenfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "haotian-zhang");
        map_skill("unarmed", "xiantian-gong");
        map_skill("finger", "yiyang-zhi");
        map_skill("strike", "haotian-zhang");
        // map_skill("hand", "qixing-shou");
	map_skill("cuff",   "chunyang-quan");
	map_skill("whip",   "duanyun-bian");
        prepare_skill("unarmed", "xiantian-gong");

        set("no_teach/yiyang-zhi", "一阳指乃是段家秘传，我不能教你。");

        create_family("全真教", 1, "掌教");

        set("inquiry", ([
                "全真教"     : "我全真教是天下道家玄门正宗。",
                "绝招"       : "你想学什么绝招？",
                "绝技"       : "你想学什么绝招？",
                "九阴真经"   : (: ask_jiuyin :),
                "段皇爷"     : (: ask_duan :),
                "五气朝元"   : (: ask_skill1 :),
                "一气化三清" : (: ask_skill2 :),
                "化三清"     : (: ask_skill2 :),
                "天地混元"   : (: ask_skill3 :),
                "五阴焚灭"   : (: ask_skill4 :),
                "神威浩荡"   : (: ask_skill5 :),
                "三连环"     : (: ask_skill6 :),
        ]));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.hun" :),
                (: perform_action, "unarmed.fen" :),
                (: perform_action, "unarmed.dang" :),
                (: perform_action, "unarmed.jian" :),
                (: perform_action, "parry.suo" :),
                (: exert_function, "hup" :),
                (: exert_function, "shield" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));

        set_temp("apply/damage", 100);
        set_temp("apply/unarmed_damage", 100);
        set_temp("apply/armor", 200);

        set("master_ob",5);
	setup();
        carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))
                return;

        if (ob->query_int() < 35)
        {
                command("say 你的悟性还不够，还是先找我那几个徒弟学习吧。");
                return;
        }


        if ((int)ob->query_skill("xiantian-gong", 1) < 120
           && (int)ob->query_skill("quanzhen-xinfa", 1) < 120)
        {
                command("say 你的本门内功心法火候不足，只怕难以"
                        "领略更高深的武功。");
                return;
        }

        if (count_lt(ob->query("combat_exp"), 450000))
        {
                command("say 你的实战经验太差，看来难以领略更高深的武功。");
                return;
        }

        if ((int)ob->query("shen") < 80000)
        {
                command("say 行侠仗义是我辈学武人的宗旨，你多做些侠"
                        "义之事，我方能收你为徒。");
                return;
        }
        command("say 不错，以你资质定可传我衣钵！我就收下你这个徒弟了。");
        command("recruit " + ob->query("id"));
}


mixed ask_skill1()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xiantian-gong/hup"))
                return "这招我不是已经教会你了吗？";

        if (me->query("family/family_name") != query("family/family_name"))
                return "阁下与贫道素不相识，不知此话从何说起？";

        if (me->query_skill("xiantian-gong", 1) < 1)
                return "你连先天功都没学，何谈绝招可言？";

        if (me->query("family/gongji") < 500)
                return "你在我全真教内甚无作为，这招我暂时还不能传你。";

        if (me->query("shen") < 100000)
                return "你的侠义正事还做得不够，这招我暂时还不能传你。";

        if (me->query_skill("xiantian-gong", 1) < 200)
                return "你先天功的修为不够，还是练高了再来吧。";

        if (me->query("max_neili") < 2000)
                return "你的内力修为仍不足，还是练高点再来吧。";

        message_sort(HIY "\n$n" HIY "微微一笑，从怀中轻轻取出了一本"
                     "小册子，指着其中的一段对$N" HIY "细说良久，$N"
                     HIY "一边听一边点头。\n\n" NOR, me,
                     this_object()); 

        command("nod");
        command("say 你自己下去练吧。");
        tell_object(me, HIC "你学会了「五气朝元」。\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xiantian-gong/hup", 1);
        me->add("family/gongji", -500);

        return 1;
}

mixed ask_skill2()
{
        object me;

        me = this_player();

        if (me->query("can_perform/quanzhen-jian/hua"))
                return "你全真剑法已达如此造诣，我已没什么可教的了。";

        if (me->query("family/family_name") != query("family/family_name"))
                return "阁下与贫道素不相识，不知此话从何说起？";

        if (me->query_skill("quanzhen-jian", 1) < 1)
                return "你连全真剑法都没学，何谈绝招可言？";

        if (me->query("family/gongji") < 1600)
                return "你在我全真教内甚无作为，这招我暂时还不能传你。";

        if (me->query("shen") < 100000)
                return "你的侠义正事还做得不够，这招我暂时还不能传你。";

        if (me->query_skill("quanzhen-jian", 1) < 200)
                return "你对我派剑法的了解还不够透彻，研究透了再来找我吧。";

        if (me->query_skill("xiantian-gong", 1) < 100 &&
            me->query_skill("quanzhen-xinfa", 1) < 100)
                return "你全真的内功的修为不够，还是练高了再来吧。";

        if (me->query("max_neili") < 4500)
                return "你的内力修为仍不足，还是练高点再来吧。";

        message_sort(HIY "\n$n" HIY "哈哈一笑，随手从道袍上撕下一角布"
                     "条，内力吞吐间，只见那布条登时变得如同坚铁，伸手"
                     "刺处，变幻无方，宛若三把长剑齐出，招式当真绝妙无"
                     "比。只看得$N" HIY "目瞪口呆。\n\n"
                     NOR, me, this_object()); 

        command("haha");
        command("say 你自己下去揣摩吧，切记莫走进邪魔歪道！");
        tell_object(me, HIC "你学会了「一气化三清」。\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        /*
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        */
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("quanzhen-jian"))
                me->improve_skill("quanzhen-jian", 1500000);
        if (me->can_improve_skill("quanzhen-jian"))
                me->improve_skill("quanzhen-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/quanzhen-jian/hua", 1);
        me->add("family/gongji", -1600);

        return 1;
}

mixed ask_skill6() 
{
        object me;
        me = this_player();

        if (me->query("can_perform/quanzhen-jian/lian"))
                return "你全真剑法已达如此造诣，我已没什么可教的了。";

        if (me->query("family/family_name") != query("family/family_name"))
                return "阁下与贫道素不相识，不知此话从何说起？";

        if (me->query_skill("quanzhen-jian", 1) < 1)
                return "你连全真剑法都没学，何谈绝招可言？";

        if (me->query("family/gongji") < 1600)
                return "你在我全真教内甚无作为，这招我暂时还不能传你。";

        if (me->query("shen") < 100000)
                return "你的侠义正事还做得不够，这招我暂时还不能传你。";

        if (me->query_skill("quanzhen-jian", 1) < 200)
                return "你对我派剑法的了解还不够透彻，研究透了再来找我吧。";

        if (me->query_skill("quanzhen-xinfa", 1) < 100)
                return "你全真心法的修为不够，还是练高了再来吧。";

        if (me->query("max_neili") < 4500)
                return "你的内力修为仍不足，还是练高点再来吧。";

        command("haha");
        command("say 你自己下去揣摩吧，切记莫走进邪魔歪道！");
        tell_object(me, HIC "你学会了「三连环绝技」。\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("quanzhen-xinfa"))
                me->improve_skill("quanzhen-xinfa", 1500000);
        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", 1500000);
        if (me->can_improve_skill("quanzhen-jian"))
                me->improve_skill("quanzhen-jian", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/quanzhen-jian/lian", 1);
        me->add("family/gongji", -1600);

        return 1;
}


mixed ask_skill3()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xiantian-gong/hun"))
                return "这招你不是已经学会了吗？";

        if (me->query("family/family_name") != query("family/family_name"))
                return "阁下与贫道素不相识，不知此话从何说起？";

        if (me->query_skill("xiantian-gong", 1) < 1)
                return "你连先天功都没学，何谈绝招可言？";

        if (me->query("family/gongji") < 1800)
                return "你在我全真教内甚无作为，这招我暂时还不能传你。";

        if (me->query("shen") < 120000)
                return "你的侠义正事还做得不够，这招我暂时还不能传你。";

        if (me->query_skill("xiantian-gong", 1) < 200)
                return "你先天功的修为不够，还是练高了再来吧。";

        if (me->query("max_neili") < 4000)
                return "你的内力修为仍不足，还是练高点再来吧。";

        message_sort(HIY "\n$n" HIY "哈哈一笑，对$N" HIY "说道：“你的"
                     "先天功达此境界，实属不凡，今日为师传你这招又有何"
                     "妨？”说罢$n" HIY "便摆开架势，慢慢地演示招数。\n"
                     "\n" NOR, me, this_object()); 

        command("nod");
        command("say 招式便是如此，能否领悟就靠你自己了。");
        tell_object(me, HIC "你学会了「天地混元」。\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xiantian-gong/hun", 1);
        me->add("family/gongji", -1800);

        return 1;
}

mixed ask_skill4()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xiantian-gong/fen"))
                return "这招你不是已经学会了吗？";

        if (me->query("family/family_name") != query("family/family_name"))
                return "阁下与贫道素不相识，不知此话从何说起？";

        if (me->query_skill("xiantian-gong", 1) < 1)
                return "你连先天功都没学，何谈绝招可言？";

        if (me->query("family/gongji") < 2000)
                return "你在我全真教内甚无作为，这招我暂时还不能传你。";

        if (me->query("shen") < 130000)
                return "你的侠义正事还做得不够，这招我暂时还不能传你。";

        if (me->query_skill("xiantian-gong", 1) < 240)
                return "你先天功的修为不够，还是练高了再来吧。";

        if (me->query("max_neili") < 4000)
                return "你的内力修为仍不足，还是练高点再来吧。";

        message_sort(HIY "\n$n" HIY "微微一笑，对$N" HIY "说道：“难得"
                     "你有如此造诣，今日师父就传你这招，可看好了！”$n"
                     HIY "随即一声清哮，全身真气急速运转，引得周围气流"
                     "波动不已。左掌微微一抖，先天真气随招式而荡漾，激"
                     "起千层气浪，威力之强，当可用惊天地、泣鬼神来描述"
                     "，直看得$N" HIY "目瞪口呆。\n\n" NOR, me,
                     this_object()); 

        command("nod");
        command("say 招式便是如此，你自己下去练吧。");
        tell_object(me, HIC "你学会了「五阴焚灭」。\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xiantian-gong/fen", 1);
        me->add("family/gongji", -2000);

        return 1;
}

mixed ask_skill5()
{
        object me;

        me = this_player();

        if (me->query("can_perform/xiantian-gong/dang"))
                return "这招你不是已经学会了吗？";

        if (me->query("family/family_name") != query("family/family_name"))
                return "阁下与贫道素不相识，不知此话从何说起？";

        if (me->query_skill("xiantian-gong", 1) < 1)
                return "你连先天功都没学，何谈绝招可言？";

        if (me->query("family/gongji") < 2500)
                return "你在我全真教内甚无作为，这招我暂时还不能传你。";

        if (me->query("shen") < 150000)
                return "你的侠义正事还做得不够，这招我暂时还不能传你。";

        if (me->query_skill("xiantian-gong", 1) < 240)
                return "你先天功的修为不够，还是练高了再来吧。";

        if (me->query("max_neili") < 5000)
                return "你的内力修为仍不足，还是练高点再来吧。";

        if (! me->query("can_perform/xiantian-gong/fen"))
                return "此招乃是由「五阴焚灭」升华而来，你还是逐步学习吧？";

        message_sort(HIY "\n$n" HIY "微微点了点头，随手搭在$N" HIY "的"
                     "肩上，突然$N" HIY "陡觉全身筋脉剧震，内息澎湃汹涌"
                     "之极，犹如江河绝堤，便欲冲关破出一般，不由大惊。"
                     "\n\n" NOR, me, this_object()); 

        command("haha");
        command("say 你可明白了？");
        tell_object(me, HIC "你学会了「神威浩荡」。\n" NOR);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("force"))
                me->improve_skill("force", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("unarmed"))
                me->improve_skill("unarmed", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        if (me->can_improve_skill("xiantian-gong"))
                me->improve_skill("xiantian-gong", 1500000);
        me->improve_skill("martial-cognize", 1500000);
        me->set("can_perform/xiantian-gong/dang", 1);
        me->add("family/gongji", -2500);

        return 1;
}

string ask_jiuyin()
{
        mapping fam;
        int lvl_force;

        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "全真教")
                return RANK_D->query_respect(this_player()) +
                "与本教毫无瓜葛，这话从何说起？";
        if (!(lvl_force = this_player()->query_skill("force", 1))
            || lvl_force < 50)
                return RANK_D->query_respect(this_player()) +
                "的基本内功火候如此之浅，强练真经上的上乘武功有害无益。";
        return "九阴真经是天下武学正宗，我已交给我师弟周伯通保管。";
}

string ask_duan()
{
        return "你问段皇爷做甚么，莫非想与他为难？\n"; 
}

/*
void unconcious()
{
        die();
}
*/
       void die(object killer)  
           {  
                   object ob;  
                   ob = new("/kungfu/class/quanzhen/wang"); 
                   ob->move(environment());  
                   ::die(killer);  
           }  
