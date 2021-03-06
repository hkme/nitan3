// YinTianZheng.c
// pal 1997.05.09

#include <ansi.h>
#include "fawang.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("殷天正", ({"yin tianzheng", "yin", "tianzheng", }));
	set("long",
        "他是一位身材魁梧的秃老者，身穿一件白色长袍。\n"
        "他长眉胜雪，垂下眼角，鼻子钩曲，犹如鹰嘴。\n"
	);
                                                          
	set("title",HIG "明教" HIW "白眉鹰王" NOR);
	set("level",9);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 72);
	set("shen_type", 1);
	set("per", 22);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 900000);
	set("score", 1000000);

	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("sword", 180);
	set_skill("cuff", 180);
	set_skill("strike", 180);
	set_skill("claw", 220);
	set_skill("literate", 120);

	set_skill("shenghuo-xinfa", 180);
	set_skill("xiaoyaoyou", 180);
	set_skill("shenghuo-quan", 180);
	set_skill("guangming-zhang", 180);
	set_skill("liehuo-jian", 180);
	set_skill("sougu", 220);

	map_skill("force", "shenghuo-xinfa");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("strike", "guangming-zhang");
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "sougu");
	map_skill("claw", "sougu");
	map_skill("cuff", "shenghuo-quan");

	prepare_skill("claw", "sougu");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform muyeyingyang") :),
	}) );
	create_family("明教", 35, "护法法王");
        set("inherit_title",HIG"明教"NOR"光明散人"NOR);
	set("master_ob",3);
	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}
int accept_ask(object me, string topic)
{
        switch (topic)
        {

        case "赤血爪" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/sougu/xue",
                           "name"    : "赤血爪",
                           "sk1"     : "sougu",
                           "lv1"     : 140,
                           "neili"   : 2000,
                           "gongxian": 800,
                           "shen"    : 100000, ]));
                break;

        default:
                return 0;
        }
}

