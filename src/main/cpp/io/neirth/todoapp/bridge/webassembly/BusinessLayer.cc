#include <emscripten/bind.h>

#include "../../utility/Utilities.h"

using namespace io::neirth::todoapp::utility;


EMSCRIPTEN_BINDINGS(Utilities) {
    emscripten::class_<Utilities>("Utilities")
            .class_function("get_service_layer", &Utilities::get_service_layer)
            .class_function("get_exception_message", &Utilities::get_exception_message);
}