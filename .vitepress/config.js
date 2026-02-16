import { defineConfig } from 'vitepress'

// https://vitepress.dev/reference/site-config
export default defineConfig({
  srcDir: "docs",
  base: '/',

  title: "sourcekit.cc",
  description: "Fuzhou Sourcekit Electronics Ltd",
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
