import { defineConfig } from 'vitepress'

const tagId = 'G-TK6CPWVPRE';

// https://vitepress.dev/reference/site-config
export default defineConfig({
  srcDir: "docs",
  base: '/',

  // Internationalization configuration
  locales: {
    root: {
      label: 'English',
      lang: 'en',
      title: "sourcekit.cc",
      description: "Fuzhou Sourcekit Electronics Ltd",
      themeConfig: {
        nav: [
          { text: 'Home', link: '/' },
        ],
        sidebar: [
          {
            text: 'Hardware',
            items: [
              { text: 'PiTray clip', link: '/PiTray-clip' },
              { text: 'PiTray mini', link: '/PiTray-mini' },
              // { text: 'Circus Goggles', link: '/CircusGoggles' },
            ]
          }
        ],
        socialLinks: [],
        // English-specific sidebar labels if needed
        outlineTitle: 'On this page',
        lastUpdatedText: 'Last updated',
        darkModeSwitchLabel: 'Appearance',
        sidebarMenuLabel: 'Menu',
        returnToTopLabel: 'Return to top',
        langMenuLabel: 'Change language',
        editLink: {
          pattern: 'https://github.com/aguegu/sourcekit.cc/edit/main/docs/:path',
          text: 'Edit this page on GitHub'
        }
      }
    },
    zh: {
      label: '简体中文',
      lang: 'zh',
      title: "sourcekit.cc",
      // description: "",
      themeConfig: {
        nav: [
          { text: '首页', link: '/zh/' },
        ],
        sidebar: [
          {
            text: '硬件产品',
            items: [
              { text: 'PiTray clip', link: '/zh/PiTray-clip' },
              { text: 'PiTray mini', link: '/zh/PiTray-mini' },
              { text: 'CircusGoggles', link: '/zh/CircusGoggles' },
            ]
          }
        ],
        socialLinks: [],
        // Chinese-specific sidebar labels
        outlineTitle: '本页目录',
        lastUpdatedText: '最后更新',
        darkModeSwitchLabel: '外观',
        sidebarMenuLabel: '菜单',
        returnToTopLabel: '回到顶部',
        langMenuLabel: '切换语言',
        editLink: {
          pattern: 'https://github.com/aguegu/sourcekit.cc/edit/main/docs/:path',
          text: '在 GitHub 上编辑此页'
        }
      }
    }
  },

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
    search: {
      provider: 'local'
    },

    // Language switcher in navbar
    localeLinks: {
      text: '',
      items: [
        { text: 'English', link: '/' },
        { text: '简体中文', link: '/zh/' }
      ]
    }
  }
})
