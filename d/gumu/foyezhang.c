
inherit ROOM;

void create()
{
        set("short", "��ү��");
        set("long", @LONG
ֻ���˴���Ϊ��������һ����Ժ����ַ���������ɴ�ػ�
�ƣ���Ժ�Ķ�ԫ�����ϡ�ɼ����ƺ�����һ����С����Ժ����
����һƬƽԭ��
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "east"  : __DIR__"shenheyuan",
        ]));

        setup();
        replace_program(ROOM);
}