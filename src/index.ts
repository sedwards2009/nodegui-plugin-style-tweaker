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

    setStyleHint(hint: number /* QStyleStyleHint */, value: number): void {
        this.native.setStyleHint(hint, value);
    }

    unsetStyleHint(hint: number /* QStyleStyleHint */): void {
        this.native.unsetStyleHint(hint);
    }
 }
