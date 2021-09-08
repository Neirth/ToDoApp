#ifndef TODOAPP_MAINSERVICE_H
#define TODOAPP_MAINSERVICE_H

#include <list>
#include <fruit/fruit.h>

#include "../domain/Task.h"
#include "../repository/TaskRepository.h"

using namespace io::neirth::todoapp::domain;
using namespace io::neirth::todoapp::repository;

namespace io::neirth::todoapp::service {
    class MainService {
        private:
            std::shared_ptr<TaskRepository> task_repository;
            
        public:
            INJECT(MainService(std::shared_ptr<TaskRepository> task_repository));

            void insert_task(const std::shared_ptr<Task>& task_obj);
            void update_task(const std::shared_ptr<Task>& task_obj);
            void delete_task(const std::shared_ptr<Task>& task_obj);

            std::shared_ptr<Task> find_by_id_task(long id);
            std::vector<std::shared_ptr<Task>> find_all_task();
    };
}

#endif //TODOAPP_MAINSERVICE_H
