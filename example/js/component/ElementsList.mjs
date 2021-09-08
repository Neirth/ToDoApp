export class ElementsList extends HTMLElement {
    constructor() {
        super();
        this.attachShadow({ mode: 'open' })
    }

    async connectedCallback() {
        let t1 = performance.now()

        await this.refresh()

        let t2 = performance.now()
        console.log("Time used to render the data: " + (t2 - t1))
    }

    async refresh() {
        try {
            let tasks = await window.business_layer.find_all_task()

            this.renderTable(tasks)
        } catch (ex) {
            console.error(window.exception_message(ex))
        }
    }

    async searchWithId(id) {
        try {
            if (id) {
                let task = await window.business_layer.find_by_id_task(id)

                let tasks_table = ""

                tasks_table += `
                    <tr>
                        <td>${task.id}</td> 
                        <td>${task.name}</td>
                        <td>${task.description}</td>
                        <td>${new Date(task.timestamp * 1000).toUTCString()}</td>
                        <td>${task.is_complete ? "Yes" : "No"}</td>
                        <td>
                            <button onclick="(async () => {
                                let task_obj = await window.business_layer.find_by_id_task(${task.id})
                                await window.business_layer.delete_task(task_obj)
    
                                document.getElementById('list').refresh()                
                            })()" >Delete</button>
                        </td>
                    </tr>
                `

                this.render(tasks_table)
            } else {
                await this.refresh()
            }
        } catch (ex) {
            console.error(window.exception_message(ex))
        }
    }

    renderTable(tasks) {
        let tasks_table = ""

        for (let i = 0; i < tasks.size(); i++) {
            let task = tasks.get(i)

            tasks_table += `
                <tr>
                    <td>${task.id}</td> 
                    <td>${task.name}</td>
                    <td>${task.description}</td>
                    <td>${new Date(task.timestamp * 1000).toUTCString()}</td>
                    <td>${task.is_complete ? "Yes" : "No"}</td>
                    <td>
                        <button onclick="(async () => {
                            let task_obj = await window.business_layer.find_by_id_task(${task.id})
                            await window.business_layer.delete_task(task_obj)
    
                            document.getElementById('list').refresh()                
                        })()" >Delete</button>
                    </td>
                </tr>
            `
        }

        this.render(tasks_table)
    }

    render(tasks_table) {
        this.shadowRoot.innerHTML = `
            <section id="elements-list">
                <link rel="stylesheet" href="./css/elements-list.css">
                <table class="table-color">
                    <thead>
                        <td>ID</td>
                        <td>Name</td>
                        <td>Description</td>
                        <td>Created Date</td>
                        <td>Is Complete?</td>
                        <td>Actions</td>
                    </thead>
                    <tbody>
                        ${tasks_table}
                    </tbody>
                </table>
            </section>
        `
    }
}