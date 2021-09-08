#ifndef TODOAPP_TASKREPOSITORY_H
#define TODOAPP_TASKREPOSITORY_H

#include <memory>
#include <vector>

#include <fruit/fruit.h>

#include "../domain/Task.h"

using namespace io::neirth::todoapp::domain;

namespace io::neirth::todoapp::repository {
    class TaskRepository {
        public:
            INJECT(TaskRepository()) = default;

            void insert_task(const std::shared_ptr<Task>& task_obj);
            void update_task(const std::shared_ptr<Task>& task_obj);
            void delete_task(const std::shared_ptr<Task>& task_obj);

            std::shared_ptr<Task> find_by_id_task(long id);
            std::vector<std::shared_ptr<Task>> find_all_task();
    };
}

#endif //TODOAPP_TASKREPOSITORY_H
