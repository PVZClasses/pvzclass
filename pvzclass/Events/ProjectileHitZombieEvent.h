#pragma once
#include "TemplateEvent.h"

// �ӵ����н�ʬ�¼�
// �������ӵ��뱻���еĽ�ʬ
// �޷���ֵ
class ProjectileHitZombieEvent : public TemplateEvent<std::function<
	void(std::shared_ptr<PVZ::Projectile>, std::shared_ptr<PVZ::Zombie>)>>
{
public:
	ProjectileHitZombieEvent();
	void handle(CONTEXT& context) override;
};

BYTE __asm__46CE77[]
{
	0x85, 0xC0, 0x74, 0x01, 0x90, 0xC2, 0x04, 0x00
};

ProjectileHitZombieEvent::ProjectileHitZombieEvent()
{
	PVZ::Memory::WriteArray<BYTE>(0x46CE77, STRING(__asm__46CE77));
	address = 0x46CE7B;
}

void ProjectileHitZombieEvent::handle(CONTEXT& context)
{
	auto projectile = std::make_shared<PVZ::Projectile>(context.Ebp);
	auto zombie = std::make_shared<PVZ::Zombie>(context.Eax);
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i](projectile, zombie);
	}
}