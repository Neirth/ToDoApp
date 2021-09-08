#include <thread>
#include <future>
#include <utility>

#include "MainService.h"

using namespace io::neirth::todoapp::domain;

namespace io::neirth::todoapp::service {
    MainService::MainService(std::shared_ptr<TaskRepository> task_repository) {
        this->task_repository = std::move(task_repository);
    }

    void MainService::insert_task(const std::shared_ptr<Task>& task_obj) {
        this->task_repository->insert_task(task_obj);
    }

    void MainService::update_task(const std::shared_ptr<Task>& task_obj) {
        this->task_repository->update_task(task_obj);
    }

    void MainService::delete_task(const std::shared_ptr<Task>& task_obj) {
        this->task_repository->delete_task(task_obj);
    }

    std::shared_ptr<Task> MainService::find_by_id_task(long id) {
        return this->task_repository->find_by_id_task(id);
    }

    std::vector<std::shared_ptr<Task>> MainService::find_all_task() {
        return this->task_repository->find_all_task();
    }
}
