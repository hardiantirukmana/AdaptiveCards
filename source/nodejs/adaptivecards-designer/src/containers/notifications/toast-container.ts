import * as Adaptive from "adaptivecards";
import * as Designer from "../../adaptivecards-designer";

var windowsNotificationConfiguration = require("../../../../../../samples/HostConfig/windows-notification.json");

export class ToastContainer extends Designer.HostContainer {
    public renderTo(hostElement: HTMLElement) {
        this.cardHost.classList.add("toast-card");

        let frame = document.createElement("div");
        frame.className = "toast-frame";
        frame.appendChild(this.cardHost);

        hostElement.appendChild(frame);
    }

    public getHostConfig(): Adaptive.HostConfig {
        return new Adaptive.HostConfig(windowsNotificationConfiguration);
    }
}
