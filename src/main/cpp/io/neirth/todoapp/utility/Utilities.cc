#include <fruit/fruit.h>

#include "Utilities.h"

using namespace io::neirth::todoapp::service;
using namespace io::neirth::todoapp::repository;

namespace io::neirth::todoapp::utility {
    fruit::Component<MainService> Utilities::get_component_injectable() {
        return fruit::createComponent()
                .registerConstructor<TaskRepository()>()
                .registerConstructor<MainService(std::shared_ptr<TaskRepository>)>();
    }

    std::unique_ptr<MainService> Utilities::get_service_layer() {
        fruit::Injector<MainService> injector(Utilities::get_component_injectable);

        return std::make_unique<MainService>(injector.get<MainService>());
    }

    std::string Utilities::get_exception_message(intptr_t exceptionPtr) {
        return {reinterpret_cast<std::exception *>(exceptionPtr)->what()};
    }

    std::string Utilities::bool_as_text(bool b){
        std::stringstream converter;
        converter << std::boolalpha << b;   // flag boolalpha calls converter.setf(std::ios_base::boolalpha)
        return converter.str();
    }
}