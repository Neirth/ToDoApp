#include <list>
#include <future>
#include <stdexcept>

#include <json/json.h>
#include <emscripten/val.h>

#include "../domain/Task.h"
#include "../repository/TaskRepository.h"
#include "../bridge/webassembly/Repository.cc"

using namespace io::neirth::todoapp::domain;

namespace io::neirth::todoapp::repository {
    void TaskRepository::insert_task(const std::shared_ptr<Task>& task_obj) {
        std::string json_str = task_obj->to_json();

        long task_id = insert_task_js(json_str.c_str());

        if (task_id < 0) {
            throw std::runtime_error("TaskRepository::insert_task: error inserting task");
        } else {
            task_obj->set_id(task_id);
        }
    }

    void TaskRepository::update_task(const std::shared_ptr<Task>& task_obj) {
        std::string json_str = task_obj->to_json();

        bool without_error = update_task_js(task_obj->get_id(), json_str.c_str());

        if (!without_error) {
            throw std::runtime_error("TaskRepository::update_task: error updating task");
        }
    }

    void TaskRepository::delete_task(const std::shared_ptr<Task>& task_obj) {
        bool without_error = delete_task_js(task_obj->get_id());

        if (!without_error) {
            throw std::runtime_error("TaskRepository::delete_task: error deleting task");
        }
    }

    std::shared_ptr<Task> TaskRepository::find_by_id_task(long id) {
        std::string json_str = std::string(find_by_id_task_js(id));

        if (json_str.empty()) {
            throw std::runtime_error("TaskRepository::find_by_id_task: error finding task");
        }

        Json::Value root;
        Json::CharReaderBuilder builder {};

        std::unique_ptr<Json::CharReader> reader (builder.newCharReader() );

        if (reader->parse(json_str.c_str(), json_str.c_str() + json_str.size(), &root, nullptr)) {
            return Task::from_json(root);
        } else {
            throw std::runtime_error("TaskRepository::find_by_id_task: error parsing task");
        }        
    }

    std::vector<std::shared_ptr<Task>> TaskRepository::find_all_task() {
        std::vector<std::shared_ptr<Task>> tasks;
        
        std::string json_str(find_all_task_js());

        if (json_str.empty()) {
            throw std::runtime_error("TaskRepository::find_all_task: error finding tasks");
        }

        Json::Value root;
        Json::CharReaderBuilder builder {};

        std::unique_ptr<Json::CharReader> reader ( builder.newCharReader() );
        
        if (reader->parse(json_str.c_str(), json_str.c_str() + json_str.size(), &root, nullptr)) {
            for (auto & it : root) {
                tasks.push_back(Task::from_json(it));
            }
        } else {
            throw std::runtime_error("TaskRepository::find_all_task: error parsing tasks");
        }

        return tasks;
    }
}