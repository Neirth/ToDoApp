#include <emscripten/bind.h>

#include "../../domain/Task.h"

using namespace io::neirth::todoapp::domain;

EMSCRIPTEN_BINDINGS(domain_layer) {
    emscripten::class_<Task>("Task")
            .smart_ptr_constructor("Task", &std::make_shared<Task>)
            .property("id", &Task::get_id, &Task::set_id)
            .property("name", &Task::get_name, &Task::set_name)
            .property("description", &Task::get_description, &Task::set_description)
            .property("timestamp", &Task::get_timestamp, &Task::set_timestamp)
            .property("is_complete", &Task::get_complete, &Task::set_complete);
}
