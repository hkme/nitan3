inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
���߽���Ժ��ӭ����һ����ɽˮ�أ����ϰ���һ�����ι�
״��ʯͷ����˵�ǵ��껨ʯ�ٵ���ʯ��ˮ�ص����������˻��ݡ�
������һ�û����������дУ��ڸ��˴���Ժ�ӡ�
LONG);
	set("exits", ([
		"south" : __DIR__"wanghouse",
		"west"  : __DIR__"xting",
		"east"  : __DIR__"dting",
		"north" : __DIR__"whouyuan",
	]));

	set("coor/x", -470);
	set("coor/y", -180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
