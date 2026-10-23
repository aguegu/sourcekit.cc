// https://vitepress.dev/guide/custom-theme
import '@mdi/font/css/materialdesignicons.css';
import './style.css';

import DefaultTheme from 'vitepress/theme';
import Mermaid from './Mermaid.vue';

export default {
  extends: DefaultTheme,
  enhanceApp({ app }) {
    app.component('Mermaid', Mermaid);
  },
};
