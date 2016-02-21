// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int count;
        int lvl;
        int i, ap, dp;
 
        if (userp(me) && ! me->query("can_perform/lingshe-zhangfa/qianshe"))
                return notify_fail("�㲻��ʹ�á�ǧ�߳�������\n");

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("��ǧ�߳�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "staff")
                return notify_fail("������ֳ�һ���Ȳ���ʩչ��ǧ�߳�������\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ��ǧ�߳�������\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("��������������޷�ʩչ��ǧ�߳�������\n");

        if ((lvl = (int)me->query_skill("lingshe-zhangfa", 1)) < 120)
                return notify_fail("��������ȷ��������ң��޷�ʹ��ǧ�߳�����\n");

        if (me->query_skill_mapped("staff") != "lingshe-zhangfa")
                return notify_fail("��û�м��������ȷ����޷�ʹ��ǧ�߳�����\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "���һ����������ǰ�����е�" + weapon->name() +
              HIW "���������â��һ������$n" HIW "��\n" NOR;

        ap = ap_power(me, "staff"); 

        dp = dp_power(target, "parry"); 
             
        if (ap / 2 + random(ap) > dp)
        {
                msg += HIY "$n" HIY "��$N" HIY "��" + weapon->name() +
                       HIY "ʹ�û�����֣���������һ�㣬ʵ�������Եֵ���ֻ�к��ˡ�\n" NOR;
                count = lvl;
                me->add_temp("apply/attack", count);
        } else
                count = 0;

        message_combatd(msg, me, target);
        me->add("neili", -100);

        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(2) && ! target->is_busy())
                        target->start_busy(1);
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -count);
        me->start_busy(1 + random(5));
        return 1;
}
