// Room: wuguan.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��ţ���");
        set("long", @LONG
����ţ��ݡ��ڽ����к����������ܶ������С���Ǵ������߽�
��������Ȼ
�����ǵ�����ҵʦ����
�����������أ������ַ���������
�����Ṧ�������ڹ��������мܣ������ַ���^M����������  
ǽ�����Ÿ�����(tiezi)��
LONG );
	set("objects", ([
		"/d/city3/npc/mawude" : 1,
		"/d/city3/npc/zhangfang" : 1,
	]));
         set("no_fight",0);
        set("no_steal",1);
        set("no_beg",1);
        set("item_desc", ([
            "tiezi" : @TEXT
��ţ��ݾ����ߣ���������еĻ����书ѧȫ����Ҫ�Ļ����书�ǣ�

�� �����ڹ�
�� �����Ṧ
�� �����м�
�� ����ȭ�ţ��ɻ���צ���������ַ��������Ʒ�������ָ������
             ��צ���Լ�����ȭ����ѡһ�֡�
�� �����������ɻ����������������������������������ȷ�����
             �������Լ�����������ѡһ�֡�

����������������������������������������������������������
����ţ��ݡ������ڻ����书
����������������������������������������������������������
���������Ṧ (dodge)            ��������ȭ�� (cuff)
���������ڹ� (force)            ������������ (blade)
���������м� (parry)            �������������� (stick)
��������צ�� (claw)             �������������� (club)
���������ַ� (hand)             �����������ȷ� (staff)
���������Ʒ� (strike)           �������������� (sword)
��������ָ�� (finger)           �������������� (throwing)
����������������������������������������������������������
ѧϰ������: xue ʦ���� �书����
TEXT
        ]) );
	set("exits", ([
		"southwest" : "/d/city3/northroad3",
		"east"      : "/d/city3/wuguanchen",
		"south"     : "/d/city3/wuguanlong",
		"west"      : "/d/city3/wuguanxiao",
		"north"     : "/d/city3/wuguanliu",
		"up"        : "/d/city3/practice",
	]));
	set("no_clean_up", 0);
	set("coor/x", -410);
	set("coor/y", -150);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	if (!me->query_temp("marks/jinniu_paied") && (dir == "up"))
	return notify_fail("�����Ц��: ���Ǳ��ݵ��Ӳ��ܽ�ȥ�ġ�\n");
	else  return 1;
}