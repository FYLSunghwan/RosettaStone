// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// RosettaStone is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#include <Rosetta/Tasks/SimpleTasks/ControlTask.hpp>
#include <Rosetta/Tasks/SimpleTasks/IncludeTask.hpp>

namespace RosettaStone::SimpleTasks
{
ControlTask::ControlTask(EntityType entityType) : ITask(entityType)
{
    // Do nothing
}

TaskID ControlTask::GetTaskID() const
{
    return TaskID::CONTROL;
}

TaskStatus ControlTask::Impl(Player& player)
{
    auto entities =
        IncludeTask::GetEntities(m_entityType, player, m_source, m_target);
    auto& myField = player.GetFieldZone();
    auto& opField = player.opponent->GetFieldZone();

    for (auto& entity : entities)
    {
        const auto minion = dynamic_cast<Minion*>(entity);
        if (minion == nullptr)
        {
            continue;
        }

        if (myField.IsFull())
        {
            entity->Destroy();
            continue;
        }

        const auto minionClone = new Minion(*minion);
        minionClone->owner = &player;

        myField.Add(*minionClone);
        opField.Remove(*minion);
    }

    return TaskStatus::COMPLETE;
}
}  // namespace RosettaStone::SimpleTasks