export class ElementsMutation extends HTMLElement {
    constructor() {
        super()
        this.attachShadow({mode: 'open'})
    }

    async connectedCallback() {
        this.render()
    }

    render() {
        this.shadowRoot.innerHTML = `
            <section id="mutation-elements" style="padding: 1em 0">
                <link rel="stylesheet" href="./css/elements-mutation.css">

                <label for="taskId">ID: </label>
                <input id="taskId" type="number" />
                
                <label for="taskName">Name: </label>
                <input id="taskName" type="text" />
                
                <label for="taskDescription">Description: </label>
                <input id="taskDescription" type="text" />
                
                <label for="taskComplete">Complete?: </label>
                <input id="taskComplete" type="checkbox" />
                
                <button onclick="(async () => {
                    try {
                        let element = document.getElementById('mutation')
                        let taskName = element.shadowRoot.getElementById('taskName').value
                        let taskDescription = element.shadowRoot.getElementById('taskDescription').value
                        let taskComplete = element.shadowRoot.getElementById('taskComplete').checked
    
                        let task = new window.task_obj()
                        
                        task.id = -1
                        task.is_complete = taskComplete
                        task.name = taskName
                        task.description = taskDescription
                        task.timestamp = Date.now() / 1000
                                        
                        await window.business_layer.insert_task(task)
                        
                        document.getElementById('list').refresh()     
                    } catch (ex) {
                        console.error(window.exception_message(ex))
                    }
                })()">Add task</button>
                
                <button onclick='(async () => {
                    try {
                        let element = document.getElementById("mutation")
                        let taskId = element.shadowRoot.getElementById("taskId").value
                        let taskName = element.shadowRoot.getElementById("taskName").value
                        let taskDescription = element.shadowRoot.getElementById("taskDescription").value
                        let taskComplete = element.shadowRoot.getElementById("taskComplete").value
    
                        let task = new window.task_obj()
                        
                        task.id = parseInt(taskId)
                        task.is_complete = taskComplete
                        task.name = taskName
                        task.description = taskDescription
                        task.timestamp = Date.now() / 1000
                                        
                        await window.business_layer.update_task(task)
                        
                        document.getElementById("list").refresh()
                    } catch (ex) {
                        console.error(window.exception_message(ex))
                    }
                })()'>Update task</button>
            </section>
        `
    }
}