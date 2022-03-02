import { QStyle, QStylePixelMetric } from '@nodegui/nodegui';
import addon from './addon';


export class StyleTweaker extends QStyle {
    constructor(baseStyleName: string) {
        super(new addon.StyleTweaker(baseStyleName));
    }

    setPixelMetric(metric: QStylePixelMetric, value: number): void {
        this.native.setPixelMetric(metric, value);
    }

    unsetPixelMetric(metric: QStylePixelMetric): void {
        this.native.unsetPixelMetric(metric);
    }
 }
