#include <emscripten/bind.h>

#include "../../domain/Task.h"
#include "../../service/MainService.h"

using namespace io::neirth::todoapp::domain;
using namespace io::neirth::todoapp::service;

EMSCRIPTEN_BINDINGS(service_layer) {
    emscripten::class_<MainService>("MainService")
            .constructor<std::shared_ptr<TaskRepository>>()
            .function("insert_task", &MainService::insert_task)
            .function("delete_task", &MainService::delete_task)
            .function("update_task", &MainService::update_task)
            .function("find_all_task", &MainService::find_all_task)
            .function("find_by_id_task", &MainService::find_by_id_task);

    emscripten::register_vector<std::shared_ptr<Task>>("vector<shared_ptr<Task>>");
}
