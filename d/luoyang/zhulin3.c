inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������ǽ��⣬�ô��һƬ����ԣ�ӭ��ҡҷ��������Ȼ����
������������������϶�����ȴ���������ڸ��٣���������һƬ������
�������������������Ȼ���������硣
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
  		"north" : __DIR__"xiaoshe",
  		"west" : __DIR__"zhulin2",
	]));

	set("coor/x", -130);
	set("coor/y", -10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}