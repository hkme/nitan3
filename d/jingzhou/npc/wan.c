// wan ����ɽ

inherit NPC;

void create()
{
	set_name("����ɽ", ({ "wan zhenshan", "wan" }));
	set("title", "���Ŵ󵱼�");
	set("gender", "����");
	
	set("age", 50);
	set("str", 25);
	set("dex", 28);
	set("long", "����������ɽ���������ŵ��ϴ�\n");
	set("combat_exp", 35000);
	set("shen_type", 0);
	set("attitude", "heroism");

	set_skill("unarmed", 50);
	set_skill("force", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 15);

	set("neili", 500); 
	set("max_neili", 500);
	
	setup();
	carry_object(__DIR__"obj/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	
}