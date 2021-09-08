import * as Module from "./service/todoapp.js"
import { ElementsList } from './component/ElementsList.mjs'
import { ElementsMutation } from "./component/ElementsMutation.mjs";
import { ElementsSearch } from "./component/ElementsSearch.mjs";

(async function() {
    let instance = await Module.default()

    window.task_obj = instance.Task
    window.business_layer = instance.Utilities.get_service_layer()
    window.exception_message = instance.Utilities.get_exception_message

    customElements.define("editable-list", ElementsList)
    customElements.define("mutation-element", ElementsMutation)
    customElements.define("search-element", ElementsSearch)
})()