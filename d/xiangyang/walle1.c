// Room: /d/xiangyang/walle1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "ʯ��");
        set("long", @LONG
���ǵ����ͷ��ʯ�ף���Ϊ��ǽ�ܸߣ����Ժܶ���ʯ�������пɹ���������
��б�µ���
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"southup"   : "/d/xiangyang/walle3",
		"northdown" : "/d/xiangyang/eastgate1",
	]));
	set("coor/x", -250);
	set("coor/y", -100);
	set("coor/z", 10);
	setup();
}
int valid_leave(object me, string dir)
{
            string c_exp;
           int c_skill;
	if (dir == "southup" )
	{
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
                if (me->query("qi") > 10)
                {
		        me->receive_damage("qi",10);
if (count_lt(count_div(count_mul(count_mul(c_skill, c_skill), c_skill), 10), c_exp) &&  c_skill < 101)  
		        me->improve_skill("dodge", (int)me->query_skill("dodge", 1) / 5);
                } else
                {
                        me->set("qi", 0);
                        return notify_fail("��̫���ˣ�������Ϣһ����ɡ�\n");
                }
	}
	return 1;
}

