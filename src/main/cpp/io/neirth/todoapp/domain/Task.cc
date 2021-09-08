#include "Task.h"

#include <json/json.h>

#include <utility>
#include <iostream>

#include "../utility/Utilities.h"

using namespace io::neirth::todoapp::utility;

namespace io::neirth::todoapp::domain {
    Task::Task(long id, bool is_complete, std::string name, std::string description, unsigned long timestamp) {
        this->id = id;
        this->is_complete = is_complete;
        this->name = std::move(name);
        this->description = std::move(description);
        this->timestamp = timestamp;
    }

    // ID Task Property
    long Task::get_id() const {
        return this->id;
    }

    void Task::set_id(long id) {
        this->id = id;
    }

    // Name Property
    std::string Task::get_name() const {
        return this->name;
    }

    void Task::set_name(std::string name) {
        this->name = name;
    }

    // Description Property
    std::string Task::get_description() const {
        return this->description;
    }

    void Task::set_description(std::string description) {
        this->description = description;
    }

    // Time Property (In epoch time)
    unsigned long Task::get_timestamp() const {
        return this->timestamp;
    }

    void Task::set_timestamp(unsigned long timestamp) {
        this->timestamp = timestamp;
    }

    /**
     * @brief Get the status of the task
     * 
     * @return true The task is done
     * @return false The task is not done
     */
    bool Task::get_complete() const {
        return this->is_complete;
    }

    /**
     * @brief Settable is_complete property
     * 
     * @param is_complete Parameter to set
     */
    void Task::set_complete(bool is_complete) {
        this->is_complete = is_complete;
    }

    /**
     * @brief Method to convert Task to json
     * 
     * @return std::string A json representation of the Task
     */
    std::string Task::to_json() const {
        std::string json_string;

        json_string += "{";
        json_string += "\"name\": \"" + this->name + "\",";
        json_string += "\"description\": \"" + this->description + "\",";
        json_string += "\"timestamp\": " + std::to_string(this->timestamp) + ",";
        json_string += "\"is_complete\": " + Utilities::bool_as_text(this->is_complete) + "";
        json_string += "}";

        return json_string;
    }

    /**
     * @brief Method to convert JSON to Task
     * 
     * @param json A json representation of the Task
     */
    std::shared_ptr<Task> Task::from_json(const Json::Value &json) {
         if (!json.isObject()) {
             throw std::invalid_argument("Task::from_json: json is not an object");
         }

        if (!json.isMember("id")) {
            throw std::invalid_argument("Task::from_json: json does not contain id");
        } else if (!json.isMember("name")) {
            throw std::invalid_argument("Task::from_json: json does not contain name");
        } else if (!json.isMember("description")) {
            throw std::invalid_argument("Task::from_json: json does not contain description");
        } else if (!json.isMember("timestamp")) {
            throw std::invalid_argument("Task::from_json: json does not contain timestamp");
        } else if (!json.isMember("is_complete")) {
            throw std::invalid_argument("Task::from_json: json does not contain is_complete");
        }

        if (!json["id"].isInt64()) {
            throw std::invalid_argument("Task::from_json: id is not a integer");
        } else if (!json["name"].isString()) {
            throw std::invalid_argument("Task::from_json: name is not a string");
        } else if (!json["description"].isString()) {
            throw std::invalid_argument("Task::from_json: description is not a string");
        } else if (!json["timestamp"].isUInt64()) {
            throw std::invalid_argument("Task::from_json: timestamp is not an unsigned integer");
        } else if (!json["is_complete"].isBool()) {
            throw std::invalid_argument("Task::from_json: is_complete is not a boolean");
        }

        std::shared_ptr<Task> task = std::make_shared<Task>();

        task->set_id(json["id"].asInt64());
        task->set_name(json["name"].asString());
        task->set_description(json["description"].asString());
        task->set_timestamp(json["timestamp"].asUInt64());
        task->set_complete(json["is_complete"].asBool());

        return task;
    }
}