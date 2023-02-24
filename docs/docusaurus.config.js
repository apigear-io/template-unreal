// @ts-check
// Note: type annotations allow type checking and IDEs autocompletion

const lightCodeTheme = require('prism-react-renderer/themes/github');
const darkCodeTheme = require('prism-react-renderer/themes/dracula');

/** @type {import('@docusaurus/types').Config} */
const config = {
  title: 'Unreal Engine template',
  tagline: 'Extend your Unreal project with data in minutes',
  favicon: 'img/favicon.ico',

  // Set the production url of your site here
  url: 'https://apigear-io.github.io/',
  // Set the /<baseUrl>/ pathname under which your site is served
  // For GitHub pages deployment, it is often '/<projectName>/'
  baseUrl: '/template-unreal/',

  // GitHub pages deployment config.
  // If you aren't using GitHub pages, you don't need these.
  organizationName: 'apigear-io', // Usually your GitHub org/user name.
  projectName: 'template-unreal', // Usually your repo name.
  trailingSlash: false,

  onBrokenLinks: 'throw',
  onBrokenMarkdownLinks: 'warn',

  // Even if you don't use internalization, you can use this field to set useful
  // metadata like html lang. For example, if your site is Chinese, you may want
  // to replace "en" with "zh-Hans".
  i18n: {
    defaultLocale: 'en',
    locales: ['en'],
  },
  customFields: {
    heroText: 'Unreal Engine template'
  },
  presets: [
    [
      'classic',
      /** @type {import('@docusaurus/preset-classic').Options} */
      ({
        docs: {
          routeBasePath: '/',
          sidebarPath: require.resolve('./sidebars.js'),
          // Please change this to your repo.
          // Remove this to remove the "edit this page" links.
          editUrl:
            'https://github.com/apigear-io/template-unreal/edit/main/docs/',
          showLastUpdateAuthor: true,
          showLastUpdateTime: true,
        },
        blog: false,
        theme: {
          customCss: require.resolve('./src/css/custom.css'),
        },
        gtag: {
          trackingID: 'G-D2X4N3X4K7',
          anonymizeIP: true,
        },
      }),
    ],
  ],

  themeConfig:
    /** @type {import('@docusaurus/preset-classic').ThemeConfig} */
    ({
      navbar: {
        title: 'Unreal Engine template',
        logo: {
          alt: 'ApiGear Logo',
          src: 'img/icon.png',
        },
        items: [
          {
            type: 'doc',
            docId: 'intro',
            position: 'left',
            label: 'Docs',
          },
          {
            label: 'Discussions',
            href: 'https://github.com/orgs/apigear-io/discussions',
            position: 'right',
          },
          {
            href: 'https://github.com/apigear-io',
            label: 'GitHub',
            position: 'right',
          },
        ],
      },
      footer: {
        style: 'dark',
        links: [
          {
            title: 'Overview',
            items: [
              {
                label: 'Quick-Start',
                to: 'quickstart',
              }
            ],
          },
          {
            title: 'References',
            items: [
              {
                label: 'ObjectAPI',
                href: 'https://docs.apigear.io/objectapi/',
              },
              {
                label: 'ObjectLink',
                href: 'https://docs.apigear.io/objectlink/',
              },
              {
                label: 'Custom Templates',
                href: 'https://docs.apigear.io/maker/',
              },
            ],
          },
          {
            title: 'Community',
            items: [
              {
                label: 'Discussions',
                href: 'https://github.com/orgs/apigear-io/discussions',
              },
              {
                label: 'GitHub',
                href: 'https://github.com/apigear-io',
              },
            ],
          },
        ],
        copyright: `Copyright © ${new Date().getFullYear()} ApiGear UG.`,
      },
      prism: {
        theme: lightCodeTheme,
        darkTheme: darkCodeTheme,
        additionalLanguages: ['yaml', 'csharp']
      },
    }),
};

module.exports = config;
