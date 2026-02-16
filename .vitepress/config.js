import { defineConfig } from 'vitepress'

const tagId = 'G-TK6CPWVPRE';
// https://vitepress.dev/reference/site-config
export default defineConfig({
  srcDir: "docs",
  base: '/',

  title: "sourcekit.cc",
  description: "Fuzhou Sourcekit Electronics Ltd",
  head: [
    ['link', { rel: 'icon', href: '/favicon.ico' }],
    [
      'script',
      { async: '', src: `https://www.googletagmanager.com/gtag/js?id=${tagId}` }
    ],
    [
      'script',
      {},
      `window.dataLayer = window.dataLayer || [];
      function gtag(){dataLayer.push(arguments);}
      gtag('js', new Date());
      gtag('config', ${tagId});`
    ]
  ],
  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: 'Home', link: '/' },
      // { text: 'Examples', link: '/markdown-examples' }
    ],

    search: {
      provider: 'local'
    },

    sidebar: [
      {
        text: 'Hardware',
        items: [
          { text: 'PiTray clip', link: '/PiTray-clip' },
          { text: 'PiTray mini', link: '/PiTray-mini' },
          // { text: 'Markdown Examples', link: '/markdown-examples' },
          // { text: 'Runtime API Examples', link: '/api-examples' }
        ]
      }
    ],

    socialLinks: [
      // { icon: 'github', link: 'https://github.com/vuejs/vitepress' }
    ]
  }
})
