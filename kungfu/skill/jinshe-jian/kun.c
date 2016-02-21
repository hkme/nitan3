#include <ansi.h>
#include <combat.h>

#define HUI "��" HIG "�������" NOR "��"

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
	object weapon;
	string msg;
        int level, ap, dp;
        /*
        if (userp(me) && ! me->query("can_perform/jinshe-jian/kun"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");
        */
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" HUI "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

        level = me->query_skill("jinshe-jian", 1);

        if (level < 140)
		return notify_fail("����߽���������죬����ʩչ" HUI "��\n");

        if (me->query_skill_mapped("sword") != "jinshe-jian")
                return notify_fail("��û�м������߽���������ʩչ" HUI "��\n");

        if (me->query("neili") < 200)
                return notify_fail("�����ڵ���������������ʩչ" HUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIG "\n$N" HIG "��̾һ��������" + weapon->name() + HIG "����"
              "���߰�Ĳ���$n" HIG "��\n" NOR;

        message_sort(msg, me, target);

        me->add("neili", -140);
        ap = ap_power(me, "sword");
        dp = dp_power(target, "parry");

	if (ap / 2 + random(ap) > dp)
        {
		msg = HIY "һ�����������$n�ѱ�$N" HIY "����Ŀ��Ͼ�ӣ���æ���ң�\n" NOR;
                target->start_busy(1 + random(ap / 80));
                me->start_busy(1);
	} else
        {
		msg = CYN "����$n" CYN "������$N"
                      CYN "����ͼ���򶨽��У�һ˿���ҡ�\n" NOR;
                me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}