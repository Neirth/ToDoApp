#ifndef TODOAPP_TASK_H
#define TODOAPP_TASK_H

#include <string>
#include <chrono>

#include <json/json.h>

namespace io::neirth::todoapp::domain {
    class Task {
        private:
            long id;
            bool is_complete;

            std::string name;
            std::string description;
            unsigned long timestamp;

        public:
            Task() = default;
            Task(long id, bool is_complete, std::string name, std::string description, unsigned long timestamp);

            // ID Task Property
            long get_id() const;
            void set_id(long task_id);

            // Name Property
            std::string get_name() const;
            void set_name(std::string name);

            // Description Property
            std::string get_description() const;
            void set_description(std::string description);

            // Time Property (In epoch time)
            unsigned long get_timestamp() const;
            void set_timestamp(unsigned long time);

            // Is Complete Property
            bool get_complete() const;
            void set_complete(bool is_complete);

            std::string to_json() const;
            static std::shared_ptr<Task> from_json(const Json::Value& json);
    };
}

#endif //TODOAPP_TASK_H
