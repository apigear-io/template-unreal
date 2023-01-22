import React from 'react';
import clsx from 'clsx';
import styles from './styles.module.css';

const FeatureList = [
  {
    title: 'Minimal API',
    description: (
      <>
        Only the defined API is exposed to the user. No unnecessary clutter, no distraction
      </>
    ),
  },
  {
    title: 'Blueprint ready',
    description: (
      <>
        All APIs can be used directly within in Blueprints
      </>
    ),
  },
  {
    title: 'Local or remote data',
    description: (
      <>
        Use a local data source or connect to a remote data source via other technology templates
      </>
    ),
  },
];

function Feature({ Svg, title, description }) {
  return (
    <div className={clsx('col col--4')}>
      <div className="text--center">
      </div>
      <div className="text--center padding-horiz--md">
        <h2>{title}</h2>
        <p>{description}</p>
      </div>
    </div>
  );
}

export default function HomepageFeatures() {
  return (
    <section className={styles.features}>
      <div className="container">
        <div className="row">
          {FeatureList.map((props, idx) => (
            <Feature key={idx} {...props} />
          ))}
        </div>
      </div>
    </section>
  );
}
