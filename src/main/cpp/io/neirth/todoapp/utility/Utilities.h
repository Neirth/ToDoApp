#ifndef TODOAPP_UTILITIES_H
#define TODOAPP_UTILITIES_H

#include <fruit/fruit.h>

#include "../service/MainService.h"

using namespace io::neirth::todoapp::service;

namespace io::neirth::todoapp::utility {
    class Utilities {
        protected:
            static fruit::Component<MainService> get_component_injectable();

        public:
            static std::unique_ptr<MainService> get_service_layer();
            static std::string get_exception_message(intptr_t exceptionPtr);

            static std::string bool_as_text(bool b);
    };
}

#endif //TODOAPP_UTILITIES_H
