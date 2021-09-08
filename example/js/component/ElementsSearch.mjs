export class ElementsSearch extends HTMLElement {
    constructor() {
        super()
        this.attachShadow({mode: 'open'})
    }

    async connectedCallback() {
        this.render()
    }

    render() {
        this.shadowRoot.innerHTML = `
            <section id="element-search" style="padding: 1em 0">
                <link rel="stylesheet" href="./css/elements-search.css">

                <label for="taskId">Search by ID: </label>
                <input id="taskId" type="number" />
                <button onclick="(async () => {
                    try {
                        let element = document.getElementById('search')
                        let taskId = element.shadowRoot.getElementById('taskId').value
    
                        await document.getElementById('list').searchWithId(parseInt(taskId))
                    } catch (ex) {
                        console.error(window.exception_message(ex))
                    }
                })()">Search Task</button>
            </section>
        `
    }
}