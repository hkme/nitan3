// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// yin2.c 殷野王

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

string ask_xunluo();

void create()
{
        set_name("殷野王",({"yin yewang", "yin", "yewang"}));
        set("title","明教天鹰分舵天微堂堂主");
        set("long", "他手摇折扇，行路足下生沙不起，便如是在水面上飘浮一般。\n"+
                    "这人绿的左襟上绣着一只小小黑鹰，双翅展开。他四十来岁\n"+
                    "年纪，但一双眼睛犹如冷电，精光四射，气势慑人。就是明\n"+
                    "教天鹰分舵天微堂堂主。当代明教教主的亲舅父殷野王。\n");
        set("age", 41);
        set("no_bark",1);
        set("env/wimpy", 40);
        set("attitude", "peaceful");
        set("shen", -8000);
        set("str", 25);
        set("int", 22);
        set("con", 25);
        set("dex", 25);
        set("per", 24);
        set("level", 12);        
        set("max_qi", 1500);
        set("max_jing", 1300);
        set("jiali", 50);
        set("combat_exp", 800000);        

        set_skill("claw",110); 
        set_skill("dodge",110);
        set_skill("force", 110);
        set_skill("literate",110);
        set_skill("qingfu-shenfa", 110);
        set_skill("shenghuo-shengong", 110);
        set_skill("yingzhua-shou",110);
        set_skill("liehuo-jian",110);
        set_skill("lieyan-dao",110);
        set_skill("parry", 110);        
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qingfu-shenfa");
        map_skill("claw", "yingzhua-shou");
        map_skill("parry", "yingzhua-shou");
        
        prepare_skill("claw","yingzhua-shou");

        set("inquiry", ([
                "画印"  : (: ask_xunluo :),
        ]));
        set("xl", 8);
        set("xl2", "yin2");
        create_family("明教",37,"弟子");
        
        set("master_ob",2);
	setup();
        carry_object("/d/mingjiao/obj/green-cloth")->wear();       
}

void attempt_apprentice(object ob)
{        
        mapping fam = ob->query("family");

        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 500) {
		command("say " + RANK_D->query_respect(ob) +
			"有所不知，我平生最恨奸诈之人，你正气太低，我不能让你用明教武功害人。");
		return;
	}
	
        if (! fam)
        {
                command("hmm");
                command("say "+RANK_D->query_respect(ob)+"还是先去跟殷家三兄弟学点基本功再来吧。"); 
                return;
        }

        if ((int)ob->query_skill("shenghuo-shengong", 1) < 50) 
        {
                command("say 要学更为高深的武功，必须有高深的内功修为。"); 
                command("say " + RANK_D->query_respect(ob)+"是否还应该在圣火神功上多下点功夫？");
                return;
        }     
        command("look " + ob->query("id"));
        command("say 嗯，看你还是个学武的料，我就收下你吧！");
        command("say 多谢明尊敝佑，让我明教又得一良材，为康扶正义，把我明教发扬光大吧。");
        command("recruit " + ob->query("id"));
        ob->set("title","明教天微堂主座下香主");
}

int accept_object(object who, object ob)
{
        int r;
        object me = this_object();
        
        if (r = ::accept_object(who, ob))
                return r;        
        
        if (me->query("family/family_name") != "明教" || ob->query("name") != "守卫书")
        {
                command("? "+who->query("id"));
                command("say 你给我东西有什么企图？！");
                return 0;
        }
        if (! who->query_temp("shouwei"))
        {
                command("say 你是哪来的，没得到常遇春的允许不许守卫！");
                return 0;
        }
        if (ob->query("name") == "守卫书")
        {
                command("say 好吧，你既然有守卫书，就在这和我在这里一起守卫吧。");
                who->apply_condition("mj_shouwei", random(4) + 7);
                who->set_temp("shouweied", 1);
                return 1;
        }
        return 1;
}

#include "xunluo.h";
