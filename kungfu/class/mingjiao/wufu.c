// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// wufu.c 殷无福

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

string ask_xunluo();

void create()
{
        set_name("殷无福", ({ "yin wufu", "yin", "wufu" }));
        set("title","明教天鹰分舵属下");
        set("age", 45);
	set("long","他是殷家的朴人。\n");
	set("str", 23);
        set("int", 20);
        set("con", 23);
        set("dex", 23);
        set("per", 10);
        set("level", 8);
        set("combat_exp", 350000);
        set("attitude", "peaceful");
        
        set_skill("dodge", 90);
        set_skill("blade", 90);
        set_skill("force", 90);
        set_skill("qingfu-shenfa", 90);
        set_skill("shenghuo-shengong", 90);
        set_skill("yingzhua-shou", 90);
        set_skill("lieyan-dao", 90);
        set_skill("claw", 90); 
        set_skill("parry", 90);
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qingfu-shenfa");
        map_skill("claw", "yingzhua-shou");
        map_skill("parry", "yingzhua-shou");
        map_skill("blade", "lieyan-dao");
        
        prepare_skill("claw","yingzhua-shou");
        
        set("inquiry", ([
                "画印"  : (: ask_xunluo :),
        ]));
        set("xl", 9);
        set("xl2", "yinwufu");
        create_family("明教", 38, "弟子");     
        set("master_ob",1);
	setup();
        
        carry_object("/d/mingjiao/obj/green-cloth")->wear();       
}

void attempt_apprentice(object ob)
{        
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 10)
        {
                command("say 你行侠仗义的事做得还不够，还是请回吧。");
                return;
        }
        
        command("look " + ob->query("id"));
        command("say 嗯，看你还是个学武的料，我就收下你吧！");
        command("say 多谢明尊敝佑，让我明教又得一良材，为康扶正义，把我明教发扬光大吧。");
        command("recruit " + ob->query("id"));
        ob->set("title","明教天微堂教众");
}

#include "xunluo.h";
