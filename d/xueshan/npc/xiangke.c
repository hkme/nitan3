// /d/xueshan/xiangke.c
// xiangke.c �����

inherit NPC;

void create()
{
        int age;
        age = 20 + random(40);
        
        set_name("�����", ({ "jinxiang ke", "ke", "guest" }));
        set("gender", "����");
        set("age", age);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set("apply/attack", 15);
        set("apply/defense", 15);
        set("apply/damage", 5);
        set("combat_exp", 150+age*10);
        set("shen_type", 1);
        setup();
        add_money("coin", 100+age/10);
        carry_object("/d/xueshan/obj/suyouguan");
}
        

