#include <emscripten.h>

EM_JS(long, insert_task_js, (const char *task_str), {
    return Asyncify.handleSleep(wake => {
        const idb = window.indexedDB || window.mozIndexedDB || window.webkitIndexedDB || window.msIndexedDB;

        const task_aux = UTF8ToString(task_str);

        const request = idb.open('todoapp', 1);
        request.onupgradeneeded = () => request.result.createObjectStore('tasks', {keyPath :'id', autoIncrement : true});
        request.onerror = (event) => wake(null);

        request.onsuccess = (event) => {
            const transaction = request.result.transaction("tasks", "readwrite");
            const store = transaction.objectStore("tasks");

            const operation = store.add(JSON.parse(task_aux));

            operation.onerror = (event) => wake(-1);
            operation.onsuccess = (event) => wake(operation.result);
        };
    });
})

EM_JS(bool, update_task_js, (long task_id, const char *task_str), {
    return Asyncify.handleSleep(wake => {
        const idb = window.indexedDB || window.mozIndexedDB || window.webkitIndexedDB || window.msIndexedDB;

        const task_aux = UTF8ToString(task_str);

        const request = idb.open('todoapp', 1);
        request.onupgradeneeded = () => request.result.createObjectStore('tasks', {keyPath :'id', autoIncrement : true});
        request.onerror = (event) => wake(null);

        request.onsuccess = (event) => {
            const transaction = request.result.transaction("tasks", "readwrite");
            const store = transaction.objectStore("tasks");

            const task_obj = JSON.parse(task_aux);
            task_obj["id"] = task_id;

            const operation = store.put(task_obj);

            operation.onerror = (event) => wake(false);
            operation.onsuccess = (event) => wake(true);
        };
    });
})

EM_JS(bool, delete_task_js, (long task_id), {
    return Asyncify.handleSleep(wake => {
        const idb = window.indexedDB || window.mozIndexedDB || window.webkitIndexedDB || window.msIndexedDB;

        const request = idb.open('todoapp', 1);
        request.onupgradeneeded = () => request.result.createObjectStore('tasks', {keyPath :'id', autoIncrement : true});
        request.onerror = (event) => wake(null);

        request.onsuccess = (event) => {
            const transaction = request.result.transaction("tasks", "readwrite");
            const store = transaction.objectStore("tasks");

            const operation = store.
            delete (task_id);

            operation.onerror = (event) => wake(false);
            operation.onsuccess = (event) => wake(true);
        };
    });
})

EM_JS(char *, find_by_id_task_js, (long task_id), {
    return Asyncify.handleSleep(wake => {
        const idb = window.indexedDB || window.mozIndexedDB || window.webkitIndexedDB || window.msIndexedDB;

        const request = idb.open('todoapp', 1);
        request.onupgradeneeded = () => request.result.createObjectStore('tasks', {keyPath :'id', autoIncrement : true});
        request.onerror = (event) => wake(null);

        request.onsuccess = (event) => {
            const transaction = request.result.transaction("tasks", "readwrite");
            const store = transaction.objectStore("tasks");

            const operation = store.get(task_id);

            operation.onerror = (event) => wake("");
            operation.onsuccess = (event) => wake(allocateUTF8OnStack(operation.result ? JSON.stringify(operation.result) : ""));
        };
    });
})

EM_JS(char *, find_all_task_js, (), {
    return Asyncify.handleSleep(wake => {
        const idb = window.indexedDB || window.mozIndexedDB || window.webkitIndexedDB || window.msIndexedDB;

        const request = idb.open('todoapp', 1);
        request.onupgradeneeded = () => request.result.createObjectStore('tasks', {keyPath :'id', autoIncrement : true});
        request.onerror = (event) => wake(null);

        request.onsuccess = (event) => {
            const transaction = request.result.transaction("tasks", "readwrite");
            const store = transaction.objectStore("tasks");

            const operation = store.getAll();

            operation.onerror = (event) => wake("");
            operation.onsuccess = (event) => wake(allocateUTF8OnStack(operation.result ? JSON.stringify(operation.result) : ""));
        };
    });
})