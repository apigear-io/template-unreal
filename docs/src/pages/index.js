import React from 'react';
import clsx from 'clsx';
import Link from '@docusaurus/Link';
import useDocusaurusContext from '@docusaurus/useDocusaurusContext';
import Layout from '@theme/Layout';
import HomepageFeatures from '@site/src/components/HomepageFeatures';
import useBaseUrl from '@docusaurus/useBaseUrl';
import Admonition from '@theme/Admonition';

import styles from './index.module.css';

function HomepageHeader() {
  const { siteConfig } = useDocusaurusContext();
  return (
    <header className={clsx('hero', styles.heroBanner)}>
      <div className="container">
        <img className={styles.heroImage} src={useBaseUrl('img/icon.png')} alt="ApiGear logo" />
        <h1 className="hero__title">{siteConfig.customFields.heroText}</h1>
        <p className="hero__subtitle">{siteConfig.tagline}</p>
        <div className={styles.buttons}>
          <Link
            className="button button--primary button--lg"
            to="/intro">
            Get Started
          </Link>
        </div>
      </div>
    </header>
  );
}

export default function Home() {
  const { siteConfig } = useDocusaurusContext();
  return (
    <Layout
      title={siteConfig.tagline}
      description="{siteConfig.tagline}">
      <HomepageHeader />
      <main>
        <HomepageFeatures /><div className={styles.tip}>
        <Admonition type="tip" icon="💡" title="UE4 and UE5 support">
          <p>
            The template is fully functional with UE4 and UE5
          </p>
        </Admonition></div>
      </main>
    </Layout>
  );
}
